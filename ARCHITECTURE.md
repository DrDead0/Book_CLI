#  Book CLI System Architecture

This document defines the architectural principles, component relationships, data flows, and planned structural expansions of Book CLI.



## 1. Design Philosophy

1. **Zero Unnecessary Allocations:** Avoid heap-heavy object hierarchies where static dispatch or stateless execution suffices.
2. **Fail-Fast Error Handling:** Validate system preconditions (e.g., filesystem existence, type checking, token counts) before executing state-altering actions.
3. **Namespace Isolation:** Commands are stateless operations grouped in domain namespaces to prevent class bloat.
4. **Standard-First Tooling:** Rely on modern C++ standard library utilities (`<filesystem>`, `<string_view>`, `<vector>`) over heavy third-party dependencies.


## 2. Directory Layout

~~~text
Book_CLI/
├── CMakeLists.txt          # Build definition and compiler configuration
├── include/                # Public interface definitions (Header files)
│   ├── shell.hpp           # REPL and command routing declarations
│   ├── workspace.hpp       # Workspace subsystem interface
│   └── (future headers)    # indexer.hpp, runner.hpp, vcs.hpp
├── src/                    # Implementation units
│   ├── main.cpp            # Application entry point
│   ├── shell/
│   │   └── shell.cpp       # Token parser & command router
│   ├── command/
│   │   └── workspace.cpp   # Workspace execution logic
│   └── (future modules)    # index/, runner/, vcs/
└── build/                  # Artifacts generated during build
~~~



## 3. Current Subsystem Architecture (v0.2.x)

### Components:
* **REPL Entry (`main.cpp`):** Starts the application lifecycle.
* **Input Tokenizer (`Shell::parseInput`):** Converts raw string stream input into token vectors delimited by whitespace.
* **Dispatcher (`Shell::executeCommand`):** Directs the first token (`args[0]`) to the responsible namespace handler, passing the full argument context.
* **Command Handler (`WorkspaceCommand`):** Inspects `args[1..n]`, validates inputs, checks disk state via `std::filesystem::exists()`, and applies filesystem mutations using the `<filesystem>` standard library.



## 4. Planned Subsystems & Future Expansion

To support the full vision of Book CLI, the architecture will expand into layered, decoupled engines:

### 4.1 Indexer & Search Engine (`src/index/`)
* **Multi-threaded Traversal:** Implements non-blocking directory walks across designated roots using thread pools.
* **In-Memory Search Trie:** Enables sub-millisecond keyword and fuzzy matching for `book search <query>`.

### 4.2 Storage & State Persistence (`src/storage/`)
* Maintains global configuration files.
* Serializes workspace states, project index caches, and recently visited projects without locking the terminal thread.

### 4.3 Task Execution Engine (`src/runner/`)
* Process abstraction wrapping OS process spawning.
* Project-aware build and test runner routing commands to underlying toolchains.

### 4.4 VCS Wrapper Subsystem (`src/vcs/`)
* Lightweight Git execution wrapper reading and parsing working directory states, active branch pointers, and commit workflows.
