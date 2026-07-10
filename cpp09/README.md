# CPP09

<h1 align="center">42_CPP09_1337</h1>

The `cpp09` module finishes the C++ piscine with STL-based problem solving. It emphasizes container choice, parsing, and efficient algorithms under stricter constraints.

## Description

This module is about solving practical tasks using standard containers and algorithms while keeping the implementation efficient and robust. It is the closest part of the curriculum to production-style C++ problem solving.

## Exercises

- `ex00` - Bitcoin exchange rate parsing and validation.
- `ex01` - Reverse Polish Notation calculator.
- `ex02` - PmergeMe and merge-insert style sorting with performance constraints.

## Usage

Build the exercise you are working on, then run it against the subject input format.

```bash
cd ex01
make
./rpn "8 9 +"
```

This module often rewards careful command-line testing, because parsing mistakes are usually the first source of bugs.

## Concepts Covered

- Input parsing is critical because each exercise expects a strict format.
- Validation and error handling prevent malformed data from reaching the core logic.
- STL containers let you compare different data structures for the same task.
- Algorithmic processing is the heart of the reverse polish and sorting exercises.
- Efficient sorting strategies matter in `PmergeMe`, where the algorithm choice affects runtime.
- Performance awareness is important because the module compares behavior under load.

## Build

Use the Makefile in the exercise directory:

```bash
make
```

## Notes

- The `ex00 helpers` folder contains support code used by the module.
- Validate malformed input early and clearly.
- Keep the implementation efficient enough for larger datasets.
