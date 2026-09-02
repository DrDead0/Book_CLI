#pragma once
#include "../core/command.hpp"
#include<vector>
#include <string>

class WorkspaceCommand : public ICommand{
    public: 
        void execute(const std::vector<std::string>& args) override;
};