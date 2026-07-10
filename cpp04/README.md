# CPP04

<h1 align="center">42_CPP04_1337</h1>

The `cpp04` module explores subtype polymorphism, abstract classes, deep copies, and interfaces. This is where C++ object-oriented design becomes much more expressive.

## Description

The exercises show why virtual functions matter, how to separate base behavior from specialized behavior, and how to manage deep copies when objects own dynamic resources.

## Exercises

- `ex00` - Polymorphism and virtual functions with animals.
- `ex01` - Deeper object ownership with `Brain` and deep copies.
- `ex02` - Abstract classes and proper polymorphic design.
- `ex03` - Materia source, cloneable objects, and an interface-based system.

## Usage

Compile the desired exercise and run it from its own folder.

```bash
cd ex03
make
./materia
```

This module is worth running more than once, because the output makes it easier to see whether polymorphic calls and deep copies behave correctly.

## Concepts Covered

- Virtual functions allow the correct override to run through a base pointer or reference.
- Subtype polymorphism gives each derived type its own version of the same behavior.
- Abstract base classes define contracts that derived classes must complete.
- Copy constructor and assignment operator behavior are important when an object owns data that must be duplicated.
- Deep copy versus shallow copy is the key idea when resources cannot be shared safely.
- Interfaces and clone semantics are used in the materia exercise to create and copy polymorphic objects.

## Build

Each exercise provides its own Makefile:

```bash
make
```

## Tips

- Always verify destructor behavior through the base class.
- If a class owns memory, copying must be handled with care.
- Design the public interface first, then fill in the implementation details.
