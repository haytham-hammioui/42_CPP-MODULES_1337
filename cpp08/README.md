# CPP08

<h1 align="center">42_CPP08_1337</h1>

The `cpp08` module expands generic programming into STL-friendly utilities. It combines templates, iterators, and algorithmic thinking around standard containers.

## Description

The exercises are centered on reusable containers and algorithms. This module helps you become comfortable with the STL mindset: generic interfaces, efficient iteration, and clean abstractions.

## Exercises

- `ex00` - Easy find: searching inside containers.
- `ex01` - Span: storing numbers and measuring ranges efficiently.
- `ex02` - Mutant stack: adapting stack behavior with iterators.

## Usage

Build the target exercise and run it with the provided sample or your own test cases.

```bash
cd ex01
make
./span
```

The exercises are intentionally small, so you should spend most of your time testing edge cases and verifying iterator behavior.

## Concepts Covered

- STL containers give you the standard data structures used throughout modern C++.
- Iterators are the universal interface for walking through containers.
- Template-based utilities keep the code generic and reusable.
- Algorithmic search appears in the container lookup exercise.
- Range calculations are the core idea of `Span`, where you measure distances between stored values.
- Container adapters are explored through the stack wrapper that exposes iteration.

## Build

Each exercise folder includes its own Makefile:

```bash
make
```

## Tips

- Prefer standard algorithms when they match the problem.
- Watch complexity when working with large ranges.
- Keep iterator support consistent with the container interface.
