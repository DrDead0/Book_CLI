#include ".././include/utils/state_manager.hpp"
#include <cstddef>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;

std::string StateManager::getStateFilePath(){
    std::string home_dir;

    #ifdef _WIN32
        home_dir = std::getenv("USERPROFILE"); // for windows user file detection
    #else
        home_dir = std::getenv("HOME"); // for linux / mac user file detection
    #endif
    
    fs::path book_dir = fs::path(home_dir) / ".bookcli";
    if(!fs::exists(book_dir)){
        fs::create_directory(book_dir);
    }
    return (book_dir/"workspace.txt").string();
}


std::unordered_map<std::string, std::string> StateManager::getWorkspace(){
    std::unordered_map <std::string, std::string> workspaces;
    std::ifstream file(getStateFilePath());
    std::string line;

    while (std::getline(file,line)){
        size_t delimiter = line.find('=');
        if (delimiter != std::string::npos){
            std:: string name = line.substr(0, delimiter);
            std:: string path = line.substr(delimiter + 1);
            workspaces[name] = path;
        }

    };
    return workspaces;
}


void StateManager::saveWorkspace(const std::string &name, const std::string &path){
    auto workspaces = getWorkspace();
    workspaces[name] = path;

    std::ofstream file(getStateFilePath(),std::ios::trunc);
    for(const auto& [w_name,w_path]:workspaces){
        file<< w_name<<"="<<w_path<<"\n";
    }

}

void StateManager::removeWorkspace(const std::string& name){
    auto workspaces = getWorkspace();
    workspaces.erase(name);

    std::ofstream file(getStateFilePath(),std::ios::trunc);
    for(const auto& [w_name,w_path]:workspaces){
        file<<w_name<<"="<<w_path<<"\n";
    }
}