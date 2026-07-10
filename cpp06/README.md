# CPP06

<h1 align="center">42_CPP06_1337</h1>

The `cpp06` module covers casting, serialization, and type identification. It is a focused module about understanding how C++ handles conversions and runtime type information.

## Description

The exercises show when explicit casts are needed, how to convert objects to raw data and back, and how to distinguish types safely at runtime.

## Exercises

- `ex00` - Scalar conversion from strings to numeric types.
- `ex01` - Serialization and pointer round-tripping.
- `ex02` - Runtime type identification with `dynamic_cast`.

## Usage

Compile the exercise you want to inspect and run it with different inputs.

```bash
cd ex00
make
./convert
```

This module is especially useful when you try tricky input values such as special floating-point strings, invalid numbers, or mixed runtime types.

## Concepts Covered

- Static, reinterpret, const, and dynamic casts show the different levels of control C++ gives you for conversions.
- Scalar parsing and conversion explain how text becomes numeric output in a controlled way.
- Serialization basics show how to turn structured data into raw storage and restore it later.
- Runtime type identification helps you discover the real derived type behind a base pointer.
- Safe polymorphic downcasting is the main reason `dynamic_cast` appears in this module.

## Build

Build each exercise with the provided Makefile:

```bash
make
```

## Tips

- Validate impossible inputs before converting them.
- Keep conversion logic explicit and traceable.
- Use the safest cast that fits the problem.
