//
// Created by odin on 3/23/17.
//
#include "CppAP_library.h"

int main(int argc, char *args[]) {
    auto flags = std::make_shared<std::map<std::string, bool>>();
    auto arguments = std::make_shared<std::map<std::string, std::string>>();

    (*flags)["test"];
    (*arguments)["MyString"];

    if (CppAP::parse_arguments(argc, args, arguments, flags)) {
        std::cout << flags->operator[]("test") << std::endl;
        std::cout << arguments->operator[]("MyString") << std::endl;
    }
}