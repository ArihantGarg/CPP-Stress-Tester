<p align="center">
  <img src="https://cdn-icons-png.flaticon.com/512/6295/6295417.png" width="100" />
</p>
<p align="center">
    <h1 align="center">CPP-STRESS-TESTER</h1>
</p>
<p align="center">
    <em>Automated stress testing framework for C++ programs with customizable test case generation and result verification</em>
</p>
<p align="center">
	<img src="https://img.shields.io/github/license/ArihantGarg/CPP-Stress-Tester?style=flat&color=0080ff" alt="license">
	<img src="https://img.shields.io/github/last-commit/ArihantGarg/CPP-Stress-Tester?style=flat&logo=git&logoColor=white&color=0080ff" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/ArihantGarg/CPP-Stress-Tester?style=flat&color=0080ff" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/ArihantGarg/CPP-Stress-Tester?style=flat&color=0080ff" alt="repo-language-count">
<p>
<p align="center">
		<em>Developed with the software and tools below.</em>
</p>
<hr>

##  Quick Links

> - [ Overview](#overview)
> - [ Repository Structure](#repository-structure)
> - [ Getting Started](#getting-started)
>   - [ Installation](#installation)
>   - [ Running CPP-Stress-Tester](#running-the-batch-script)
>   - [ Script Details](#batch-script-details)
> - [ Contributing](#contributing)

---

##  Overview

Automated stress testing framework for C++ programs with customizable test case generation and result verification

---

##  Repository Structure

```sh
└── CPP-Stress-Tester/
    ├── LICENSE
    ├── README.md
    ├── bruteforce.cpp
    ├── bruteforce.txt
    ├── check.cpp
    ├── check.txt
    ├── checker.cpp
    ├── generator.cpp
    ├── input.txt
    └── script.bat
```

---

## Getting Started

### Prerequisites

- Windows OS
- g++ compiler (part of MinGW or similar)

### Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/your-username/AutomatedLogger.git
    cd AutomatedLogger
    ```

2. Ensure `g++` is installed and accessible from the command line. You can check by running:
    ```sh
    g++ --version
    ```

### Running the Batch Script

1. Navigate to the directory containing the batch script:
    ```sh
    cd /path/to/your/batch/script
    ```

2. Double-click the batch file or run it from the command line:
    ```sh
    .\script.bat
    ```

### Batch Script Details

The batch script (`run.bat`) performs the following actions:
1. Compiles `generator.cpp` to `generator.exe`.
2. Compiles `bruteforce.cpp` to `bruteforce.exe`.
3. Compiles `check.cpp` to `check.exe`.
4. Compiles `checker.cpp` to `checker.exe`.
5. Executes `checker.exe`.

##  Contributing

1. **Fork the Repository**: Start by forking the project repository to your GitHub account.
2. **Clone Locally**: Clone the forked repository to your local machine using a Git client.
   ```sh
   git clone https://github.com/ArihantGarg/CPP-Stress-Tester
   ```
3. **Create a New Branch**: Always work on a new branch, giving it a descriptive name.
   ```sh
   git checkout -b new-feature-x
   ```
4. **Make Your Changes**: Develop and test your changes locally.
5. **Commit Your Changes**: Commit with a clear message describing your updates.
   ```sh
   git commit -m 'Implemented new feature x.'
   ```
6. **Push to GitHub**: Push the changes to your forked repository.
   ```sh
   git push origin new-feature-x
   ```
7. **Submit a Pull Request**: Create a PR against the original project repository. Clearly describe the changes and their motivations.

Once your PR is reviewed and approved, it will be merged into the main branch.

</details>

---
