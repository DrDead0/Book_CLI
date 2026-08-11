#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;


vector<string> parseInput(const string& input) {
    vector<string> tokens;
    stringstream ss(input);
    string word;

    while (ss >> word) {
        tokens.push_back(word);
    }
    
    return tokens;
}

int main() {
    string input;

    while (true) {
        cout <<"book> ";
        getline(cin, input);

        if (input == "exit" || input == "quit") {
            break;
        }

        vector<string> args = parseInput(input);

        if (!args.empty()) {
            cout << "Parsed " << args.size() << " arguments:\n";
            for (const string& arg : args) {
                cout << " -> " << arg << "\n";
            }
        }
    }

    return 0;
}