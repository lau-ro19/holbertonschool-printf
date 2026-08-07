# Printf partial rewrite: _printf

## Table of content

* [Overview](#overview)
* [Summary](#summary)
* [Copyright](#copyright)
* [How to install and run](#how-to-install-and-run)
  * [Prerequisites](#prerequisites)
  * [1. Downloading](#1-downloading)
  * [2. Compiling](#2-compiling)
  * [3. Starting program](#3-starting-program)
* [How to use](#how-to-use)
  * [Usage overview](#usage-overview)
  * [Example](#example)
  * [Features](#features)
  * [Accessible help](#accessible-help)
  * [Important rules and limitations](#important-rules-and-limitations)
* [Examples of use](#examples-of-use)
  * [Valid examples](#valid-examples)
  * [Failing examples](#failing-examples)
* [Technical information](#technical-information)
  * [General architecture](#general-architecture)
  * [Process flow](#process-flow)
  * [Source code file structure](#source-code-file-structure)
  * [Testing](#testing)
  * [Valgrind Output Summary](#valgrind-output-summary)
  * [Code Style Compliance](#code-style-compliance)
* [Technologies](#technologies)

---

## Overview

`_printf` is a low-level C command and formatted output function allowing the display of dynamically aggregated information by replacing format specifiers in a provided string with data from additional variadic arguments.

---

## Summary

This project demonstrates how to create a custom implementation of the C standard library `printf` function. It displays information on standard output ("terminal screen"), specifically handling single characters, full sentences, literal percent symbols, and signed decimal integers.

Please note that this is a custom version with a specific feature set adhering strictly to the GNU C89 standard and Holberton School's Betty coding style.

---

## Copyright

This program has been developed by:
* **Holberton School Students** (refer to the `AUTHORS` file for full contributor details).

Distributed under the terms of the Holberton School Software Engineering Curriculum.

---

## How to install and run

### Prerequisites

You must have C development tools and a C compiler (`gcc`) installed on your system.
* **Linux (Debian/Ubuntu):** Install build essentials via `sudo apt update && sudo apt install build-essential gcc git valgrind`.
* **Mac:** Install Xcode Command Line Tools via `xcode-select --install`.
* **Windows:** Use WSL (Windows Subsystem for Linux) with an Ubuntu distribution.

### 1. Downloading

Clone the repository to your local machine using Git:

```bash
git clone [https://github.com/lau-ro19/holbertonschool-printf.git](https://github.com/lau-ro19/holbertonschool-printf.git)
cd holbertonschool-printf
```

### 2. Compiling

Per explicit requirements, the `main` entry point function is **NOT** provided as part of the core library files. You need to write your own `main.c` file to test the function.

To compile all source files using the strict C89 flags required by the project specifications, run:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

### 3. Starting program

Once compiled, execute the binary from your terminal:

```bash
./printf
```

---

## How to use

### Usage overview

To use `_printf`, include `#include "main.h"` in your source files and invoke the function following its standard syntax:

```text
_printf( format , ...);
           |        |
           |        +--> variadic list of additional data to format.
           +----------> "instruction chain" (plain text and specifiers).
```

### Example

```c
#include "main.h"

int main(void)
{
    int len;

    len = _printf("Hello %s, score: %d%%\n", "Alice", 100);
    _printf("Printed characters: %d\n", len);

    return (0);
}
```

**Output displayed on terminal:**
```text
Hello Alice, score: 100%
Printed characters: 25
```

---

### Features

This custom implementation natively handles the following conversion commands:

| Conversion Specifier | Description of Output Behavior | Required Argument Type in `va_list` | Source Handler |
| :---: | :--- | :---: | :--- |
| `%c` | Replaces with a single character | `int` (promoted `char`) | `print_char.c` |
| `%s` | Replaces with a null-terminated string | `char *` | `print_string.c` |
| `%%` | Replaces with a single literal percent sign | None | `print_percent.c` |
| `%d` | Replaces with a signed decimal integer | `int` | `print_digit.c` |
| `%i` | Replaces with a signed base-10 integer | `int` | `print_digit.c` |

* **Return Value:** Returns total characters printed on success, or `-1` if an error occurs.

---

### Accessible help

You can consult the offline manual page created specifically for this project by typing:

```bash
man ./man_3_printf
```

To install the man page globally on your local machine:

```bash
mkdir -p ~/.local/share/man/man3/
cp ./man_3_printf ~/.local/share/man/man3/_printf.3
mandb
man 3 _printf
```

---

### Important rules and limitations

1. **Unknown Specifiers:** Pairing `%` with an unsupported specifier (e.g., `%z`) outputs both the `%` and the character literally.
2. **Type Matching:** Arguments passed after `format` MUST strictly match conversion specifiers in both expected sequence order and underlying type.
3. **NULL Format:** If the `format` string pointer itself is `NULL`, `_printf` aborts immediately and returns `-1`.
4. **NULL String Handling:** Passing a `NULL` pointer to `%s` will safely output `(null)`.
5. **Incomplete Formats:** A `format` string ending with a single `%` character without a trailing specifier triggers a `-1` error return.

---

## Examples of use

### Valid examples

| Use case | Source code call | Expected Terminal Output | Return value |
| :--- | :--- | :--- | :---: |
| `%c` — Character | `_printf("Character: %c\n", 'A');` | `Character: A` | 13 |
| `%s` — String | `_printf("String: %s\n", "Hello, World!");` | `String: Hello, World!` | 22 |
| `%d` — Negative Int | `_printf("Degrees: %d\n", -42);` | `Degrees: -42` | 13 |
| `%i` — Positive Int | `_printf("Score: %i\n", 1337);` | `Score: 1337` | 12 |
| `%%` — Percent sign | `_printf("Progress: 100%%\n");` | `Progress: 100%` | 15 |

### Failing examples

Below are illustrations of incorrect calls resulting in undefined behavior or error returns:

* **Mismatched Argument Types & Order:**
  ```c
  _printf("Hello %s, credit: %d dollars.\n", 30, "Alice");
  ```
  *Result:* Undefined behavior or crash (integer value `30` treated as invalid string memory address).

* **Missing Arguments:**
  ```c
  _printf("Hello %s, credit: %d dollars.\n", "Alice");
  ```
  *Result:* Garbage values printed for missing `%d` argument as `va_arg` reads stack memory beyond bounds.

* **Trailing Percent Sign:**
  ```c
  _printf("Incomplete specifier %");
  ```
  *Result:* Execution halts immediately and returns `-1`.

---

## Technical information

### General architecture

The software architecture relies on continuous sequential parsing of the `format` string:
1. Standard characters are written directly to standard output via custom calls to `_putchar` (wrapping system `write`).
2. When encountering `%`, control branches to parse the specifier and invoke the matching handler function (`print_char`, `print_string`, `print_percent`, or `print_digit`).
3. Execution terminates upon reaching the null byte (`\0`), returning the total printed character count.

---

### Process flow

The internal execution logic follows this process sequence (also detailed in `flowchart.png`):

```text
       [Start _printf(format, ...)]
                   |
         Is format == NULL?
        /                  \
      (Yes)                (No)
      /                      \
 Return -1               Initialize va_list
                               |
                       Loop: format[i] != '\0'
                       /                     \
                   (End)                     (Next Char)
                     |                            |
               Return count              Is format[i] == '%'?
                                         /                  \
                                       (Yes)                (No)
                                       /                      \
                       Check next character            Call _putchar(format[i])
                               |                            count++
                       Match specifier?
                      /                \
                   (Yes)               (No)
                   /                      \
       Call handler function        Print '%' and char
       (e.g., print_digit)              count += 2
```

---

### Source code file structure

| Filename | Role in Project | Functions Defined |
| :--- | :--- | :--- |
| `main.h` | Header file containing prototypes, macros, and include guards | Declarations for all functions |
| `_printf.c` | Core parsing engine and variadic argument manager | `_printf` |
| `_putchar.c` | Low-level wrapper writing single characters to `STDOUT_FILENO` | `_putchar` |
| `print_char.c` | Handler for `%c` specifier | `print_char` |
| `print_string.c` | Handler for `%s` specifier | `print_string` |
| `print_percent.c` | Handler for `%%` specifier | `print_percent` |
| `print_digit.c` | Handler for `%d` and `%i` signed decimal integers | `print_digit` |
| `man_3_printf` | Unix manual page source file | N/A |
| `flowchart.png` | Graphical architectural diagram of execution flow | N/A |
| `AUTHORS` | Repository contributor manifest | N/A |

---

### Testing

#### Valgrind Output Summary

Memory management and execution stability were verified using **Valgrind**. All allocations and stack variables execute with zero leaks.

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./printf
```

```text
==10== HEAP SUMMARY:
==10==     in use at exit: 0 bytes in 0 blocks
==10==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==10== 
==10== All heap blocks were freed -- no leaks are possible
==10== 
==10== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

#### Code Style Compliance

All `.c` and `.h` source files pass the **Betty Linter** static analysis checks without warnings or errors:

```bash
betty *.c *.h
```

---

## Technologies

* **Language:** C (GNU C89 / ISO C90 Standard)
* **Compiler:** GCC (Flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`)
* **Linter:** Betty Style (Holberton School Standard)
* **Debugging & Memory Analysis:** Valgrind
* **Version Control:** Git & GitHub