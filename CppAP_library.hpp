#ifndef ARGUMENT_PARSER_LIBRARY_H
#define ARGUMENT_PARSER_LIBRARY_H

#include <string>
#include <map>
#include <memory>
#include <exception>
#include <iostream>

namespace CppAP {
    void printHelp(std::shared_ptr<std::map<std::string, std::string>> arguments,
                   std::shared_ptr<std::map<std::string, bool>> flags) {
        std::cout << "-------------------- FLAGS --------------------" << std::endl;
        for (auto flag_iterator = flags->begin(); flag_iterator != flags->end(); ++flag_iterator)
            std::cout << "-" << flag_iterator->first << std::endl;

        std::cout << "------------------ Arguments -------------------" << std::endl;
        for (auto argument_iterator = arguments->begin(); argument_iterator != arguments->end(); ++argument_iterator)
            std::cout << argument_iterator->first << ":<value>" << std::endl;
    }


    bool parse_arguments(int argc, char *args[],
                         std::shared_ptr<std::map<std::string, std::string>> arguments,
                         std::shared_ptr<std::map<std::string, bool>> flags) {
        bool parse_successful = true;
        for (int i = 1; i < argc; ++i) {
            std::string argument = args[i];
            //its a flag
            if (argument.at(0) == '-') {
                argument = argument.substr(1);
                try {
                    flags->at(argument) = true;
                }
                catch (const std::out_of_range &oorException) {
                    std::cerr << "Flag " << argument << " not found.\n";
                    parse_successful = false;
                }

            } else // guess its an argument
            {
                std::string value = argument.substr(argument.find('=') + 1);
                std::string name = argument.substr(0, argument.find('='));
                if (!value.empty() && !name.empty()) {
                    try {
                        arguments->at(name) = value;
                    }
                    catch (const std::out_of_range &oorException) {
                        std::cerr << "Argument " << name << " not found.\n";
                        parse_successful = false;
                    }
                } else {
                    std::cerr << "Could not parse" << argument << "\n";
                }


            }
        }
        if (!parse_successful)
            printHelp(arguments, flags);

        return parse_successful;
    }
}
#endif