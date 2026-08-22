# Book CLI

A high-performance, modular Command Line Interface (CLI) built in C++23 for seamless workspace and project management. 

Book CLI interacts directly with the native operating system's filesystem to dynamically generate, navigate, and manage isolated workspace environments straight from the terminal.

##  Features (v0.2.0 Alpha)

The core workspace module is fully functional, offering the following commands:
* **`workspace create <name>`**: Allocates and generates a new workspace directory.
* **`workspace list`**: Scans and outputs all valid workspaces in the current directory.
* **`workspace open <name>`**: Safely changes the active working directory (CWD) to the target workspace.
* **`workspace remove <name>`**: Aggressively deletes a workspace and all its internal contents.

##  Architecture

Book CLI is designed with scalability and modularity in mind:
* **The Shell Router:** A central parsing engine (`shell.cpp`) tokenizes user input and safely routes the data arrays to specific modules.
* **Namespace Isolation:** Commands are isolated into lightweight `namespaces` (e.g., `WorkspaceCommand`) to prevent naming collisions and keep memory overhead virtually nonexistent.
* **Native OS Integration:** Leverages the standard C++ `<filesystem>` library for cross-platform, low-level disk operations and safety validations.

##  Usage

Launch the CLI to enter the interactive shell environment:

```text
book> workspace create backend
Success: Created workspace folder 'backend'

book> workspace list
Workspace in current directory:
 - backend

book> workspace open backend
Success: Opened workspace 'backend'

book> workspace remove backend
Success: Removed Workspace 'backend'
