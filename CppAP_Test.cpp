//
// Created by odin on 3/23/17.
//
#include "CppAP_library.h"

int main(int argc, char *args[]) {
    auto flags = std::make_shared<std::map<std::string, bool>>();
    auto arguments = std::make_shared<std::map<std::string, std::string>>();

    //creates values at test and Mystring, by trying to access it.
    (*flags)["test"];
    (*arguments)["MyString"];

    if (CppAP::parse_arguments(argc, args, arguments, flags)) {
        //prints values, if no invalid argument was given.
        std::cout << "test=" << (*flags)["test"] << std::endl;
        std::cout << "MyString=" << (*arguments)["MyString"] << std::endl;
    }
    return 0;
}