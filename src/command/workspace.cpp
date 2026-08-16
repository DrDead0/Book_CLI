#include "workspace.hpp"
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void WorkspaceCommand::execute(const vector<string>& args) {
    if (args.size() < 2) {
        cout << "Error: workspace requires a subcommand (e.g., 'workspace create <name>').\n";
        return;
    } 
    
    if (args[1] == "create") {
        if (args.size() < 3) {
            cout << "Error: You must provide a name (e.g., 'workspace create my_project').\n";
        } else {
            string workspaceName = args[2];
            
            if (fs::exists(workspaceName)) {
                cout << "Error: Workspace '" << workspaceName << "' already exists!\n";
            } else {
                if (fs::create_directory(workspaceName)) {
                    cout << "Success: Created workspace folder '" << workspaceName << "'\n";
                } else {
                    cout << "Error: Failed to create folder.\n";
                }
            }
        }
    } 
    else {
        cout << "Error: Unknown workspace subcommand '" << args[1] << "'\n";
    }
}