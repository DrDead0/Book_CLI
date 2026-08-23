#include "../../include/workspace.hpp"
#include <filesystem>
#include <iostream>
#include <vector>

using namespace std;
namespace fs = filesystem;

void WorkspaceCommand::execute(const vector<string> &args) {
  if (args.size() < 2) {
    cout << "Error: workspace requires a subcommand (e.g., 'workspace create "
            "<name>').\n";
    return;
  }

  if (args[1] == "create") {
    if (args.size() < 3) {
      cout << "Error: You must provide a name (e.g., 'workspace create "
              "my_project').\n";
    } else {
      string workspaceName = args[2];

      if (fs::exists(workspaceName)) {
        cout << "Error: Workspace '" << workspaceName << "' already exists!\n";
      } else {
        if (fs::create_directory(workspaceName)) {
          cout << "Success: Created workspace folder '" << workspaceName
               << "'\n";
        } else {
          cout << "Error: Failed to create folder.\n";
        }
      }
    }
  } else if (args[1] == "list") {
    cout << "Workspace in current directory:\n";
    string currDir = fs::current_path().string();
    for (const auto &entry : fs::directory_iterator(currDir)) {
      if (entry.is_directory()) {
        cout << " - " << entry.path().filename().string() << "\n";
      }
    }
  } else if (args[1] == "remove") {
    if (args.size() < 3) {
      cout << "Error : You must provide a workspace name to remove.\n";
    } else {
      string workspaceName = args[2];
      if (fs::exists(workspaceName)) {
        fs::remove_all(workspaceName);
        cout << "Success: Removed Workspace '" << workspaceName << "\n";
      } else {
        cout << "Error : Workspace'" << workspaceName << "does not exist.\n ";
      };
    };
  } else if (args[1] == "open") {
    if (args.size() < 3) {
      cout << "Error: you must provide a workspace name to open. \n";
    } else {
      string workspaceName = args[2];
      if (fs::exists(workspaceName) && fs::is_directory(workspaceName)) {
        fs::current_path(workspaceName);
        cout << "Success: Opened Workspace '" << workspaceName << "'\n";
      } else {
        cout << "Error: Workspace '" << workspaceName
             << "' does not exist or is not a folder.\n";
      }
    }
  } else if (args[1] == "rename") {
    if (args.size() < 4) {
      cout << "Error: you must provide the old and new name (e.g., 'workspace "
              "rename old_name new_name ')\n ";
    } else {
      string oldName = args[2];
      string newName = args[3];
      if (!fs::exists(oldName) || !fs::is_directory(oldName)) {
        cout << "Error: Workspace '" << oldName << "'doesn not exist. \n";
      } else if (fs::exists(newName)) {
        cout << "Error: Target name '" << newName << "'already exists.\n";
      } else {
        fs::rename(oldName, newName);
        cout << "Success: Renamed '" << oldName << "' to '" << newName
             << "'\n'";
      }
    }
  } else {
    cout << "Error: Unknown workspace subcommand '" << args[1] << "'\n";
  }
}