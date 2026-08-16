#pragma once
#include <string>
#include <vector>
using namespace std

class Shell {
    public:
        void run(); 

    private:
        std::vector<string> parseInput(const string& input);
        void executeCommand(const vector<string>& args);
};