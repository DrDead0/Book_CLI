#include "../../include/core/dispatcher.hpp"
#include <iostream>


void CommandDispatcher::registerCommand(const std::string& name, std::unique_ptr<ICommand> command) {
    commands[name] = std::move(command);
}


void CommandDispatcher::dispatch(const std::string& name, const std::vector<std::string>& args) {
    auto it = commands.find(name);
    
    if (it != commands.end()) {
        it->second->execute(args);
    } else {
        std::cout << "Error: Unknown command '" << name << "'. Type 'help' for a list of commands.\n";
    }
}