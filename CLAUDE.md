# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with
code in this repository.

## Project

Solutions to _Programming: Principles and Practice Using C++_ (PPP), 3rd
edition, by Bjarne Stroustrup. Each exercise lives under
`solutions/chN/excM/`.

| Chapter | Topic                                                                               |
| ------- | ----------------------------------------------------------------------------------- |
| 1       | Computers, People, and Programming                                                  |
| 2       | Hello, World! — basic I/O, types, variables                                         |
| 3       | Objects, Types, and Values                                                          |
| 4       | Computation — expressions, statements, functions                                    |
| 5       | Errors — exceptions, invariants, testing                                            |
| 6       | Writing a Program — the calculator project begins                                   |
| 7       | Completing a Program — the calculator project finished                              |
| 8       | Technicalities: Functions — declarations, headers, namespaces, separate compilation |
| 9       | Technicalities: Classes — structs, member functions, constructors, enumerations     |
| 10      | Input and Output Streams — file I/O, formatting                                     |
| 11      | Customizing I/O — user-defined operators, string streams                            |
| 12      | A Display Model                                                                     |
| 13      | Graphics Classes                                                                    |
| 14      | Graphics Class Design                                                               |
| 15      | Graphing Functions and Data                                                         |
| 16      | Graphical User Interfaces                                                           |
| 17      | Vector and Free Store — pointers, dynamic allocation                                |
| 18      | Vectors and Arrays — copying, essential operations                                  |
| 19      | Bitwise Operations; Binary I/O                                                      |
| 20      | Text Manipulation — strings, maps, regular expressions                              |
| 21      | Algorithms and Maps — STL algorithms, associative containers                        |
| 22      | Iterators and Algorithms — iterator concepts, design                                |
| 23      | Numerics — math, random numbers, matrices                                           |
| 24      | Embedded Systems Programming                                                        |
| 25      | Testing                                                                             |
| 26      | C Language                                                                          |
| 27      | The C++ Standard Library — overview of the STL                                      |

## Build Commands

```bash
make all          # build every exercise
make 9.4          # build solutions/ch9/exc4
make run-9.4      # build and run solutions/ch9/exc4
make new-9.5      # scaffold solutions/ch9/exc5/ with template makefile + main.cpp
make rm-9.5       # delete an exercise directory (prompts confirmation)
make clean        # clean all build artifacts
make fmt          # format README.md with prettier
```

CI runs `make all`, clang-format check, and clang-tidy on every push.

## Code Style

**Naming (enforced by clang-tidy):**

- `lower_case` — functions, variables, parameters, members, namespaces
- `CamelCase` — classes, structs
- `UPPER_CASE` — constants, enum constants

**Formatting (enforced by clang-format, Allman style):**

- 4-space indent, 100-column limit
- Braces on their own line (`BreakBeforeBraces: Allman`)
- Left-aligned pointers and references (`int* p`, not `int *p`)
- `'\n'` instead of `std::endl`

**Compiler:** g++, C++20, `-Wall -Werror` — all warnings are errors.

## Exercise Structure

Each exercise follows this layout:

```
solutions/chN/excM/
├── makefile       # copied from .templates/makefile
├── src/
│   └── main.cpp  # (plus additional .cpp/.h for multi-file exercises)
└── build/         # generated object files and .d dependency files
```

Multi-file exercises (e.g. ch8/exc5-9) split logic into separate modules with
their own `.h` headers under `src/`.

## Pre-commit Hooks

`.pre-commit-config.yaml` runs clang-format and clang-tidy automatically on
commit and may rewrite files. If a commit modifies staged files, re-stage and
commit again.
