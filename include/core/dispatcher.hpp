#pragma once
#include "command.hpp"
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

class CommandDispatcher{
    private:
        std::unordered_map<std::string,std::unique_ptr<ICommand>> commands;
    public:
        void registerCommand(const std::string& name,std:: unique_ptr<ICommand> commands);
        void dispatch(const std::string& name,const std::vector<std::string>& args);
};