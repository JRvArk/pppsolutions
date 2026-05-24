# PPP Solutions

[![CI](https://github.com/JRvArk/pppsolutions/actions/workflows/ci.yml/badge.svg)](https://github.com/JRvArk/pppsolutions/actions/workflows/ci.yml)

Personal solutions to
_[Programming: Principles and Practice Using C++](https://www.stroustrup.com/programming.html)_
(PPP), 3rd edition, by Bjarne Stroustrup. The book teaches C++ from the ground
up, with an emphasis on good programming practice and design. Each exercise
lives under `solutions/chN/excM/`.

## Progress

| Chapter | Exercises            |
| ------- | -------------------- |
| 2       | 4, 6, 8, 9, 10       |
| 3       | 18, 19, 20           |
| 4       | 7, 8, 11, 12, 13, 14 |
| 5       | 4                    |
| 7       | 2, 3                 |
| 8       | 2, 5–9               |
| 9       | 2, 3, 4              |
| 15      | 1                    |

## Setup

**Dependencies:**

- g++ or clang++ with C++20 support
- LLVM (for clang-format and clang-tidy)
- [pre-commit](https://pre-commit.com/) (optional, for local linting)

**macOS (Homebrew):**

```bash
brew install llvm
pip install pre-commit
pre-commit install
```

## Build

```bash
make all          # build every exercise
make 9.4          # build solutions/ch9/exc4
make run-9.4      # build and run solutions/ch9/exc4
make new-9.5      # scaffold solutions/ch9/exc5/
make rm-9.5       # delete an exercise directory (prompts confirmation)
make clean        # remove all build artifacts
```

## Layout

```
solutions/chN/excM/
├── makefile
└── src/
    └── main.cpp
```

Multi-file exercises (e.g. `ch8/exc5-9`) add extra `.cpp`/`.h` files under
`src/`.

## Code Style

Enforced by clang-format and clang-tidy (run automatically via pre-commit
hooks and CI):

- **Naming:** `lower_case` for functions/variables, `CamelCase` for types,
  `UPPER_CASE` for constants
- **Formatting:** Allman braces, 4-space indent, 100-column limit
- **Compiler flags:** `-Wall -Werror` — all warnings are errors
