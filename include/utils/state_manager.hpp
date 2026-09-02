# pragma once 
#include <string>
#include <unordered_map>


class StateManager{
    public:
        static void saveWorkspace(const std::string& name, const std::string& path);
        static void removeWorkspace(const std::string& name);
        static std::unordered_map<std::string, std::string> getWorkspace();

    private:
        static std::string getStateFilePath();


};