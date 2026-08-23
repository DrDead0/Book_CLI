#include "../../include/shell.hpp"
#include "../../include/workspace.hpp"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> Shell::parseInput(const string& input) {
    vector<string> tokens;
    stringstream ss(input);
    string word;
    while (ss >> word) {
        tokens.push_back(word);
    }
    return tokens;
}

void Shell::executeCommand(const vector<string>& args) {
    if (args.empty()) return;

    string command = args[0];

    if (command == "help") {
        cout << "BOOK v0.2\n";
        cout << "Available commands:\n  workspace, help, version, exit\n";
    } 
    else if (command == "version") {
        cout << "book-cli version 0.2\n";
    } 
    else if (command == "workspace") {
        WorkspaceCommand::execute(args);
    }
    else {
        cout << "Unknown command: " << command << "\n";
    }
}

void Shell::run() {
    string input;
    while (true) {
        cout <<"book> ";
        getline(cin, input);

        if (input == "exit" || input == "quit") {
            break;
        }

        vector<string> args = parseInput(input);
        executeCommand(args);
    }
}