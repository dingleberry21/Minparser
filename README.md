## 🛠️ Project Name

**Minparser. A minimal command-line string parser for no practical use :)**

---

### Features

* **Simplicity**: this module is not meant for heavy parsing. It's mostly a toy project that I'm thinking of updating very soon, by adding multiple flags.
* **Fast-tokenisation**: the script's purpose is to have something that returns a set of strings immediately. In the future it might be optimised even more.
* **Only useful strings**: empty strings are discarded.
---

### Pre-requisites

There are no pre-requisites. This project uses exclusively C stdlib.

### Installation

1.  Clone the repository:
    ```bash
    git clone https://github.com/dingleberry21/Minparser
    ```
2.  Navigate into the project directory:
    ```bash
    cd /Minparser
    ```
3. Compile:
    ```bash
    gcc -std=c2x -Wall -Wextra -O3 -pedantic-errors -o minparser main.c 
    ```
---

### Usage example

```bash
./minparser This, is my comma-separated, string. Perhaps it will look, good.
```
