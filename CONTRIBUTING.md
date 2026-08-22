#  Contributing to Book CLI

First off, thank you for considering contributing to Book CLI! It's people like you that make open-source tools great. 

Book CLI is an ambitious project aimed at unifying workspace management, project indexing, and version control into a single C++23 shell. We welcome all contributions, from bug reports to massive new core features.

##  Table of Contents
1. [Code of Conduct](#code-of-conduct)
2. [How Can I Contribute?](#how-can-i-contribute)
   * [Reporting Bugs](#reporting-bugs)
   * [Suggesting Enhancements](#suggesting-enhancements)
   * [Code Contributions](#code-contributions)
3. [Development Setup](#development-setup)
4. [Coding Guidelines](#coding-guidelines)
5. [Pull Request Process](#pull-request-process)


##  Code of Conduct
By participating in this project, you are expected to uphold a welcoming, inclusive, and respectful environment for everyone. Please be kind and collaborative in all issues and pull request reviews.



##  How Can I Contribute?

### Reporting Bugs
If you find a bug, please open an issue! Before creating a bug report, please check the existing issues to see if it has already been reported. When filing a bug, include:
* Your operating system and compiler version.
* The exact steps to reproduce the crash or unexpected behavior.
* What you expected to happen vs. what actually happened.

### Suggesting Enhancements
We love new ideas! If you have a feature request:
* Open an issue labeled `enhancement`.
* Explain **why** this feature would be useful to the developer workflow.
* Provide a hypothetical example of how the command would look in the CLI (e.g., `book feature <arg>`).

### Code Contributions
We use an **Issue-Driven** workflow. Please do not submit massive code changes without first opening an issue to discuss the architecture with the maintainers. This ensures your hard work doesn't get rejected because it conflicts with the project roadmap.


##  Development Setup

Book CLI is built for speed and requires a modern toolchain.

**Prerequisites:**
* A compiler fully supporting **C++23** (GCC 13+, Clang 16+, or MSVC 19.36+).
* **CMake** (v3.10 or higher).

**Build Steps:**
1. Fork the repository and clone your fork locally.
2. Generate the build files: `cmake -B build`
3. Compile the executable: `cmake --build build`
4. Run the CLI: `./build/book` (or `.\build\Debug\book.exe` on Windows).



##  Coding Guidelines

To keep the application blazing fast and maintainable, all code must follow these rules:

* **C++23 Only:** Utilize modern C++ features (structured bindings, `std::string_view`, etc.).
* **Zero Overhead Philosophy:** Avoid heavy, deeply nested Object-Oriented classes.
* **Namespaces:** Wrap command modules in stateless namespaces (e.g., `namespace WorkspaceCommand`) to isolate logic without memory overhead.
* **Header Separation:** Keep declarations in `include/*.hpp` and implementation logic in `src/**/*.cpp`.
* **Standard Library:** Rely heavily on standard libraries like `<filesystem>` and `<vector>`. Do not introduce third-party dependencies unless explicitly approved in an architectural issue.
* **Safety First:** Always validate user input bounds (e.g., `args.size()`) and use `std::filesystem::exists()` before attempting to mutate the disk.



##  Git Workflow & Pull Request Process

1. **Branching:** Create a feature branch from `main` using the issue number: 
   `git checkout -b <issue-number>-<brief-description>` (e.g., `20-add-workspace-rename`).
2. **Commits:** Write clear, present-tense commit messages ("Add rename function" not "added rename").
3. **Testing:** Ensure your code compiles locally with zero warnings before pushing.
4. **Pull Request:** Open a PR against the `main` branch. 
5. **Review:** A maintainer will review your code. You may be asked to make structural changes. Once approved, it will be merged!
