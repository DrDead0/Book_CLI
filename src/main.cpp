#include "../include/core/dispatcher.hpp"
#include "../include/core/shell.hpp"
#include "../include/commands/workspace_command.hpp"
#include <memory>
#include "../include/commands/system_command.hpp"

int main() {

  CommandDispatcher dispatcher;

  dispatcher.registerCommand("workspace", std::make_unique<WorkspaceCommand>());
  dispatcher.registerCommand("version" , std::make_unique<VersionCommand>());

  
  Shell shell(std::move(dispatcher));
  shell.run();

  return 0;
}