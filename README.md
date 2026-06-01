# Low-Level Bit Manipulation Puzzles (Work in Progress 🚀)

This repository tracks my journey through learning low-level data representation and computer architecture. I am solving complex bit-level puzzles under strict hardware-level constraints.

## 📌 Current Status
* **Phase 1: Integer Arithmetic & Bit Logic** — [IN PROGRESS] Coding basic operations, signed/unsigned behaviors, and endianness logic.
* **Phase 2: Floating-Point Representations** — [PLANNED] Manually handling the IEEE 754 standard.

## 🚫 The Constraints
To deeply understand how the CPU works, I am restricting myself from using:
* `if`, `else`, `loops` (`for`, `while`), or `switch`.
* Macros or function calls.
* Only bitwise operators (`&`, `|`, `~`, `^`, `<<`, `>>`) and basic math (`+`, `-`) are allowed in core solutions.

## 🛠️ How to Compile & Run
I created a simple Makefile to automate testing my functions as I write them.

```bash
make
./test
