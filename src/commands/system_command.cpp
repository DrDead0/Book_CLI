#include "../../include/commands/system_command.hpp"
#include<iostream>
#include<cstdlib>
#include <vector>

//version command
void VersionCommand::execute(const std::vector<std::string>& args){
    std::cout<<"BooK CLI Version 0.2.0\n";
}
//help command
void HelpCommand::execute(const std::vector<std::string>& args){
    std::cout<<"Book CLI - Master Developer Workspace Manager \n\n";
    std::cout<<"Usage: <command> [arguements.....] \n\n";
    std::cout<<"Commands: \n";
    std::cout<<"help        Shows this help message\n";
    std::cout<<"version     Shows version information\n";
    std::cout<<"clear       Clear the terminal screen \n";
    std::cout<<"workspace   Manage local developemnt workspace\n";
}

void ClearCommand::execute(const std::vector<std::string>& args){
    #ifdef _WIN32 
        std::system("cls");
    #else
        std::system("clear");
    #endif
}