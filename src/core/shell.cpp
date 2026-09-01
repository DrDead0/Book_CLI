#include "../../include/core/shell.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Shell::Shell(CommandDispatcher d) : dispatcher(std::move(d)) {};


void Shell::run(){
    std::string input;
    while(true){
        std::cout<<"book> ";
        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(input == "exit") break;

        std::istringstream stream(input);
        std::string name;
        std::vector<std::string> args;

        stream>>name;

        std::string word;
        while(stream >> word){
            args.push_back(word);
        }

        dispatcher.dispatch(name, args);
    }
}