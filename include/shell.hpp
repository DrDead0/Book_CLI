#pragma once
#include <string>
#include <vector>

class Shell {
public:
    void run(); 

private:
    std::vector<std::string> parseInput(const std::string& input);
    void executeCommand(const std::vector<std::string>& args);
};