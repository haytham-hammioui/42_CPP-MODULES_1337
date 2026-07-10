# CPP02

<h1 align="center">42_CPP02_1337</h1>

The `cpp02` module is about the fundamentals of operator overloading, canonical forms, and fixed-point arithmetic. It is a good checkpoint for understanding how C++ can model types with custom behavior.

## Description

The exercises in this module focus on writing proper class interfaces, following the orthodox canonical form, and implementing custom operators with predictable semantics.

## Exercises

- `ex00` - My First Class in C++: first class design and canonical structure.
- `ex01` - Towards a More Useful Fixed-Point Class: fixed-point arithmetic and operators.
- `ex02` - Fixed Point Arithmetic: extending the fixed-point implementation.
- `ex03` - BSP: checking whether a point belongs inside a triangle.

## Usage

Compile the exercise you are working on and run the corresponding binary.

```bash
cd ex02
make
./fixed
```

The exact executable name can vary by exercise, so check the Makefile if needed.

## Concepts Covered

- Orthodox canonical form gives each class a predictable constructor, copy, assignment, and destructor flow.
- Constructors, destructors, and copy behavior show how objects manage their own lifetime correctly.
- Operator overloading lets your custom types act like built-in numeric or utility types.
- Fixed-point representation teaches you how to store decimal values without using floating-point directly.
- Binary arithmetic and scaling explain how the raw stored value maps to the real-world value.
- Geometric reasoning is used in the triangle exercise to turn coordinates into a yes/no decision.

## Build

Use the Makefile inside each exercise directory:

```bash
make
```

## Tips

- Keep conversions explicit and predictable.
- Watch for precision loss when working with fixed-point numbers.
- Test edge cases carefully in the geometry exercise.
