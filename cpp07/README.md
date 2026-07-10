# CPP07

<h1 align="center">42_CPP07_1337</h1>

The `cpp07` module introduces templates and generic programming. The goal is to write reusable code that works across types without duplicating the implementation.

## Description

This module focuses on template functions and template classes, showing how to design generic utilities with minimal assumptions about the underlying type.

## Exercises

- `ex00` - A generic swap/min/max style exercise.
- `ex01` - Template iterators over containers and ranges.
- `ex02` - A templated array class with safe access.

## Usage

Build the exercise in its own directory and run the generated binary or tests.

```bash
cd ex02
make
./array
```

Template exercises are easier to verify when you test multiple input types and boundary cases.

## Concepts Covered

- Function templates remove the need to duplicate logic for each type.
- Class templates let a whole type become reusable across different data kinds.
- Generic algorithms show how the same code can work with multiple types when the interface is consistent.
- Iterator-style traversal is the standard way to move through a range in C++.
- Bounds checking prevents unsafe access in the templated array exercise.
- Type independence is the main design goal of the module.

## Build

Use the Makefile in each exercise directory:

```bash
make
```

## Tips

- Keep template code in headers unless the subject says otherwise.
- Make error handling clear for invalid access.
- Test templates with multiple types, not just integers.
