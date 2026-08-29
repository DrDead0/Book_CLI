#pragma once
#include <vector>
#include <string>
using namespace std;

class ICommand{
    public:
    virtual ~ICommand() = default;

    virtual void execute(const vector<string>&args) = 0;
};