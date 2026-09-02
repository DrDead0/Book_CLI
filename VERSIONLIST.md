# Book CLI Detailed Development Roadmap

##  Foundation (v0.1 & v0.2) 
*Currently migrating legacy codebase to the scalable Command Pattern architecture.*
- **Code Refactorization:** Moving from monolithic `if-else` blocks to modular `core/` and `commands/` directories.
- **Add exe Config:** Establishing CMake configuration for automated, cross-platform builds.
- **Implement persistent workspace state:** Creating a background JSON/database file to remember where user projects live.
- **Workspace Operations:** `create`, `list`, `open`, `remove`, `rename` - Core directory management.

##  Upcoming Milestones

### v0.3: Scanning & Indexing
- **3.1 Configure scan roots & filesystem traversal:** Build the logic to recursively crawl the user's hard drive efficiently.
- **3.2 Implement project/repository detection:** Teach the engine how to recognize a valid project (e.g., looking for `.git` or `package.json`).
- **3.3 Add book scan command & local index:** Allow the user to manually trigger a scan and save the results to the persistent state.
- **3.4 Add book projects command:** Display a formatted, terminal-friendly list of all indexed projects.
- **3.5 Add book info <project> command:** Retrieve and display basic metadata (language, size, last modified) for a specific workspace.

### v0.4: Search & Discovery
- **4.1 Add book search <query> command:** Implement global string matching to find projects instantly.
- **4.2 Implement project metadata searching:** Allow searching by specific tags (e.g., "language:cpp" or "type:node").
- **4.3 Implement basic search filtering and ranking:** Sort search results by relevance or recent activity rather than alphabetical order.
- **4.4 Implement index refresh mechanism:** Create a background or manual trigger to update the local database when folders are deleted or moved outside the CLI.

### v0.5: Health & System Diagnostics
- **5.1 Add book doctor global command:** Scan the entire index to check the health of all registered workspaces.
- **5.2 Add book doctor <project> specific command:** Run a targeted diagnostic on a single repository.
- **5.3 Implement checks for broken paths and missing metadata:** Identify projects in the index that have been deleted from the OS.
- **5.4 Implement checks for duplicate projects:** Warn the user if the same repository exists in multiple locations.
- **5.5 Implement large generated/build directory detection:** Flag projects with massive `node_modules` or `build` folders to help the user clear disk space.

### v0.6: Quick Access & Workflow
- **6.1 Add book recent command:** List the last 5-10 workspaces the user interacted with.
- **6.2 Add book favorite <project> command:** Pin specific workspaces to the top of lists for instant access.
- **6.3 Add book continue / resume workflow command:** Instantly open the most recently used project without specifying its name.
- **6.4 Add book history command:** Display an audit log of recent CLI actions and commands executed.

### v0.7: Build & Test Integration
- **7.1 Add book build command:** Trigger project-specific build scripts (e.g., `cmake`, `npm run build`) from the global interface.
- **7.2 Add book test command:** Trigger project-specific test suites.
- **7.3 Add book run command:** Start the project's primary development server or binary.
- **7.4 Add book clean command:** Delete generated folders (`build/`, `bin/`, `node_modules/`) to reset a project state.
- **7.5 Add project-aware book run <task> configuration:** Read local config files to map custom user scripts to standard CLI commands.

### v0.8: Version Control Automation (Git Macros)
- **8.1 Add book status command:** Check repository state without navigating to the directory.
- **8.2 Add book branch command:** Manage and switch branches remotely.
- **8.3 Add book commit command:** Stage and commit changes.
- **8.4 Add book push and book pull commands:** Sync with remote repositories.
- **8.5 Add book sync command:** A massive DX macro that strings together add, commit, and push in a single user action, supporting specific file targeting (e.g., `book push readme.md "update"`).

### v0.9: Polish & Release Prep
- **9.1 Stabilize command UX and improve error handling:** Ensure helpful error messages (no raw C++ segmentation faults) and consistent color formatting.
- **9.2 Measure startup/scan/search performance:** Optimize hash maps and file traversal to ensure sub-second response times.
- **9.3 Refactor duplicated or tightly coupled code:** Clean up the utility functions before the 1.0 lock.
- **9.4 Add meaningful tests (unit/integration):** Programmatically verify that core engine routing and file system commands work.
- **9.5 Complete prototype documentation for official Book 1.0 transition:** Write the official `README` and architectural guides.
- **Add More installation Ways:** Finalize scripts for Windows (PowerShell) and Unix (Bash) package managers.

### v1.0 & Beyond: Advanced DX Macros
- **Environment Initialization:** Commands to bootstrap new projects instantly (e.g., one command to create a folder, initialize git, scaffold Node.js/C++, and run initial installs).
- **Extensible Plugin System:** Allow custom automation scripts per workspace type.