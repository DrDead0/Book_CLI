#include "../include/shell.hpp"
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;

namespace fs = filesystem;

void load_saved_state() {
  const char *home = getenv("USERPROFILE");
  if (!home)
    home = getenv("HOME");
  if (!home)
    return;

  fs::path statePath = fs::path(home) / ".bookcli" / ".state.txt";
  if(fs::exists(statePath)){
    ifstream stateFile(statePath);
    string savedPath;
    if(getline(stateFile,savedPath) && ! savedPath.empty()){
        if(fs::exists(savedPath) && fs::is_directory(savedPath)){
            fs::current_path(savedPath);
        }
    }
  }
}

int main(){
    load_saved_state();

    Shell myShell;
    myShell.run();
    return 0 ;
}