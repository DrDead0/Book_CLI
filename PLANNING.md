# Book CLI Architecture & Execution Plan

## Core Design Philosophy
Book CLI is a developer workspace macro-engine. It reduces complex, multi-step development workflows (like version control, project discovery, and environment setup) into single, highly optimized terminal commands.

## Architecture: The Command Pattern
To support limitless future commands without degrading performance or creating spaghetti code, the application strictly isolates the routing engine from the business logic. Every feature operates as a standalone plugin.

### Directory Structure
book_cli/
├── include/
│   ├── core/                      (Untouchable Engine Blueprints)
│   │   ├── command.hpp            (The ICommand interface)
│   │   ├── dispatcher.hpp         (The router logic)
│   │   └── shell.hpp              (Terminal input capture)
│   ├── commands/                  (Feature Blueprints)
│   │   ├── workspace_command.hpp  (Directory management)
│   │   ├── git_command.hpp        (Version control macros)
│   │   └── ... 
│   └── utils/                     (Shared Infrastructure)
│       ├── file_system.hpp        (Path validation and OS directory checks)
│       └── system_runner.hpp      (Executes background terminal commands like Git/NPM)
│
├── src/
│   ├── core/                      
│   │   ├── dispatcher.cpp
│   │   └── shell.cpp
│   ├── commands/                  
│   │   ├── workspace_command.cpp  
│   │   ├── git_command.cpp       
│   │   └── ... 
│   ├── utils/                     
│   │   ├── file_system.cpp
│   │   └── system_runner.cpp
│   └── main.cpp                   (Application Entry Point)

## Request Lifecycle
1. **Capture:** `shell.cpp` captures the raw string (e.g., `push readme.md "init"`).
2. **Parse & Route:** `dispatcher.cpp` maps the first word to the `GitCommand` class memory address via an $O(1)$ hash map.
3. **Execution:** `git_command.cpp` evaluates the remaining array arguments.
4. **System Call:** The command utilizes `system_runner.cpp` to execute the corresponding OS-level operations (`git add`, `git commit`, `git push`) silently in the background.