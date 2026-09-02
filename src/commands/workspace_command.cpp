#include "../../include/commands/workspace_command.hpp"
#include<iostream>
#include<filesystem> // c++ library for OS-level directory manipulation
#include <string>
#include <vector>


namespace fs = std::filesystem;

void WorkspaceCommand::execute(const std::vector<std::string>& args){
    if(args.empty()){
        std::cout<<"Error: Workspace commmand is required an action (eg., 'create', 'remove' )\n";
        return ;
    }

    std::string action = args[0];
    //create logic
    if(action == "create"){
        if(args.size()<2){
            std::cerr<<"Error: 'create' requires a workspace name.\n";
            return;
        }
        std::string target_path = args[1];
        if(fs::exists(target_path)){
            std::cerr<<"Error: Workspace '"<<target_path<<"' already exists on disk.\n";
            return;
        }
        if(fs::create_directory(target_path)){
            std::cout<<"Success: Created Workspace folder '"<< target_path<<"'.\n";
        }else{
            std::cerr<<"Error: OS denied permission to create folder or failed to create '"<<target_path<<"'.\n";
        }
    }
    // remove logic
    else if (action == "remove") {
        if(args.size()<2){
            std::cerr<<"Error: 'remove' rquired a workspace name.\n";
            return;
        }
        std::string target_path = args[1];
        if(!fs::exists(target_path)){
            std::cerr<<"Error: Workspace '"<<target_path<<"'does not exist.\n";
            return ;
        }

        fs::remove_all(target_path);
        std::cout<<"Success: Remove workspace '"<<target_path<<"'.\n";
    
    }
    //reanme logic 
    else if (action == "rename") {
        if (args.size()<3){
            std::cerr<<"Error: 'reanme' required <old-name> <new-name>.\n";
            return ;
        }
        std::string old_name = args[1];
        std::string new_name = args[2];

        if(!fs::exists(old_name)){
            std::cerr<<"Error: Workspace '"<<old_name<<"' does not exist.\n";
            return ;
        }
        if(fs::exists(new_name)){
            std::cerr<<"Error: A workspace with name '"<<new_name<<"' already exist.\n";
            return;
        }
        fs::rename(old_name,new_name);
        std::cout<<"Success: Rename workspace '"<<old_name<<"' to '"<<new_name<<"'.\n";
    
    }
    //list logic
    else if (action == "list") {
        std::cout<<"Active Workspace in current Director.\n";
        bool found = false;

        for (const auto& entry :fs::directory_iterator(".")){
            if(entry.is_directory()){
                std::cout<<" - "<<entry.path().filename().string()<<"\n";
                found = true;
            }
        }
        if(!found){
            std::cout<<"(No workspace found).\n";

        }
    }
    //open logic
    else if (action == "open") {
        if(args.size()<2){
            std::cerr<<"Error: 'open' requires a workspace name .\n";
            return ;
        }    
        std::string target = args[1];

        if(!fs::exists(target) || !fs::is_directory(target)){
            std::cerr<<"Error: Workspace '"<<target<<"' is not a vaild directory.\n";
            return;
        }
        fs::current_path(target);
        std::cout<<"Success: Internal Context swtiched to workspace '"<<target<<"'.\n";
    }
    //unkown command error 
    else{
        std::cerr<<"Error Unknown workspace action '"<<action<<"'.\n";
    }


}