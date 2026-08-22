#  Book CLI

**Book CLI** is a modular, high-performance developer workspace manager and execution engine built with **C++23**.

Modern software engineering involves managing dozens of fragmented repositories, environments, and directories scattered across local disks. Book CLI eliminates context-switching fatigue by turning the terminal into an intelligent workspace coordinator—unifying directory orchestration, local project indexing, task running, and version control into a single continuous shell.



##  Key Highlights
* **Zero Overhead:** Written in modern C++23 with zero external runtime dependencies.
* **Native Filesystem Operations:** Direct OS-level directory traversal and manipulation via standard libraries.
* **Interactive Shell Environment:** Dedicated REPL with tokenized command dispatching.
* **Modular Namespace Architecture:** Isolated command modules preventing runtime state collisions.



##  Features (v0.2.0 Alpha)

The core workspace engine is currently active:

| Command | Description |
| :--- | :--- |
| `workspace create <name>` | Allocates and creates a new workspace directory. |
| `workspace list` | Scans and outputs all workspace directories at the current path. |
| `workspace open <name>` | Validates target path and switches active program context (CWD). |
| `workspace remove <name>` | Safely validates and deletes target workspace directory and contents. |

### Interactive REPL Example
~~~text
book> workspace create backend
Success: Created workspace folder 'backend'

book> workspace list
Workspace in current directory:
 - backend

book> workspace open backend
Success: Opened workspace 'backend'

book> workspace remove backend
Success: Removed Workspace 'backend'
~~~



##  Engineering Roadmap

Book CLI is evolving through deliberate development phases:

###  Phase 1: Advanced Workspaces (Active)
- [x] Workspace creation, listing, navigation, and deletion.
- [ ] Atomic workspace renaming (`workspace rename <name> <new-name>`).
- [ ] Persistent workspace configuration and session restore.

###  Phase 2: Indexing & Fast Search
- [ ] Multi-threaded disk scanner (`book scan`) across configured root paths.
- [ ] Project metadata extraction (detection of CMake, Cargo, npm, Go, etc.).
- [ ] Fast fuzzy search with ranking filters (`book search <query>`).
- [ ] Quick-access workflow (`book recent`, `book favorite <project>`).

###  Phase 3: Task & Process Runner
- [ ] Unified project build orchestration (`book build`).
- [ ] Test suite runner (`book test`).
- [ ] Task execution pipeline with project-aware configurations (`book run <task>`).
- [ ] Build artifact cleanup (`book clean`).

###  Phase 4: Version Control Integration
- [ ] Git repository status inspection (`book status`, `book branch`).
- [ ] Rapid staged commit shortcuts (`book commit`).
- [ ] Remote repository sync pipelines (`book push`, `book pull`, `book sync`).

###  Phase 5: System Diagnostics & Health
- [ ] Health checker (`book doctor`) for corrupted indexes, broken symlinks, and orphaned build artifacts.
- [ ] Storage analysis for oversized generated folders (`node_modules`, `build`, `target`).



##  Build & Installation

### Prerequisites
* **Compiler:** Clang 16+, GCC 13+, or MSVC 19.36+ (Full C++23 standard support required).
* **Build System:** CMake 3.10+

### Compiling from Source
~~~bash
# 1. Clone the repository
git clone [https://github.com/drdead0/Book_CLI.git](https://github.com/drdead0/Book_CLI.git)
cd Book_CLI

# 2. Configure build cache
cmake -B build

# 3. Compile binary
cmake --build build

# 4. Launch Book CLI
./build/book
~~~



##  Architecture & Contributing
* For internal design specifications, memory models, and planned subsystem pipelines, read `ARCH.md`.
* For coding standards, branch conventions, and PR guidelines, read `CONTRIBUTING.md`.



##  License
This project is licensed under the MIT License.
