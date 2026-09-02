#pragma once
#include "../core/command.hpp"
#include <vector>
#include <string>

class VersionCommand : public ICommand{
    public:
        void execute(const std::vector<std::string>& args) override;
};

class HelpCommand : public ICommand{
    public:
        void execute(const std::vector<std::string>& args) override;
};

class ClearCommand: public ICommand{
    public:
        void execute(const std::vector<std::string>& args) override;

};