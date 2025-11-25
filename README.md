# Legacy Loan Calculator Modernization (Assignment 2)

**Student ID:** 24P-3000
**Name:** PIR AHMED SHAH
**Course:** INTRODUCTION TO SOFTWARE ENGINEERING (SE1001)

---

## Project Overview

This repository contains the results of Assignment 2: fixing, refactoring, testing, and documenting a legacy C++ Simple Interest Loan Calculator. The original monolithic codebase (`main.cpp`) contained several common issues, including risks of numerical overflow, lack of input validation, and reliance on hardcoded values. This project addresses these issues by modularizing the code, implementing robust input validation, and enhancing numerical precision using `long double` for financial calculations. 

## Build, Run, and Test Instructions

The project uses a standard `makefile` for compilation and execution.

### Prerequisites

1.  **C++ Compiler:** `g++` (C++14 or newer)
2.  **Build Tool:** `make`
3.  **Testing Framework:** GoogleTest (`libgtest-dev`)
4.  **Documentation Tool:** Doxygen (`doxygen`, `graphviz`)

### 1. Build and Run the Application

To compile and run the main application:

| Command    | Description                                                                                   |
| :--------- | :-------------------------------------------------------------------------------------------- |
| `make`     | Compiles the main application (`src/main.cpp` and `src/loan.cpp`) into `dist/calculator.exe`. |
| `make run` | Executes the compiled application.                                                            |

### 2. Run Unit Tests

The tests cover Normal EMI, Input Validation, and Large Tenure calculation to ensure precision.

| Command     | Description                                                           |
| :---------- | :-------------------------------------------------------------------- |
| `make test` | Compiles and executes the unit tests defined in `tests/test_emi.cpp`. |

### 3. Generate Documentation

Doxygen generates API documentation from the comments in the header file (`src/loan.hpp`).

| Command    | Description                                                      |
| :--------- | :--------------------------------------------------------------- |
| `make dox` | Generates the HTML documentation into the `docs/html` directory. |

### 4. Cleanup

| Command      | Description                                                                                      |
| :----------- | :----------------------------------------------------------------------------------------------- |
| `make clean` | Removes the build directory (`dist`), the generated documentation (`docs`), and other artifacts. |

