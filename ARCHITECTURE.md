#  Book CLI System Architecture

This document defines the architectural principles, component relationships, data flows, and planned structural expansions of Book CLI.



## 1. Design Philosophy

1. **Zero Unnecessary Allocations:** Avoid heap-heavy object hierarchies where static dispatch or stateless execution suffices.
2. **Fail-Fast Error Handling:** Validate system preconditions (e.g., filesystem existence, type checking, token counts) before executing state-altering actions.
3. **Namespace Isolation:** Commands are stateless operations grouped in domain namespaces to prevent class bloat.
4. **Standard-First Tooling:** Rely on modern C++ standard library utilities (`<filesystem>`, `<string_view>`, `<vector>`) over heavy third-party dependencies.



## 2. Directory Layout

```text
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
