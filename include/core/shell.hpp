#pragma once
#include "dispatcher.hpp"


class Shell{
    private:
        CommandDispatcher dispatcher;
    public:
        Shell(CommandDispatcher d);
        void run();
};