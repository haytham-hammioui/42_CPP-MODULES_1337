# CPP00

<h1 align="center">42_CPP00_1337</h1>

The `cpp00` module is the starting point of the 42 C++ curriculum. It introduces the language rules that are different from C, basic compilation habits, and the first small programs written in idiomatic C++.

## Description

This module focuses on getting comfortable with C++ syntax, streams, namespaces, classes, member functions, and the first object-oriented exercises. It is built to make the transition from C to C++ feel practical instead of abstract.

## Exercises

- `ex00` - Megaphone: string handling and output formatting.
- `ex01` - PhoneBook: a small interactive class-based contact manager.
- `ex02` - Account: a banking exercise centered on static members and class behavior.

## Usage

Open the exercise you want to work on, then build and run it with the provided Makefile.

```bash
cd ex01
make
./phonebook
```

Each exercise is independent, so you can test and iterate inside its own folder without affecting the others.

## Concepts Covered

- `std::string` and `std::cout` are the first tools used to handle text and formatted output.
- Namespaces help avoid naming conflicts and prepare you for larger code bases.
- Classes and objects introduce encapsulation, the basic building block of C++ design.
- Member functions show how behavior belongs to the data it manipulates.
- `const` correctness makes interfaces safer and easier to reason about.
- Static members and methods let a class share state or behavior across all instances.

## Build

Use the provided Makefile in each exercise folder:

```bash
make
```

To clean generated files:

```bash
make clean
```

## Tips

- Keep the exercises simple and readable.
- Prefer standard C++ streams over C-style I/O when the subject allows it.
- Use the subject rules carefully, especially when formatting output.
