# CPP01

<h1 align="center">42_CPP01_1337</h1>

The `cpp01` module introduces memory management, pointers, references, dynamic allocation, and basic class interactions. The exercises become more practical and start to show why object lifetime matters in C++.

## Description

This module builds on the first steps of C++ by introducing stack versus heap allocation, references, pointers to members, file handling, and simple object composition. It is one of the first modules where ownership and lifetime become important.

## Exercises

- `ex00` - Zombie: dynamic object creation and basic class methods.
- `ex01` - Zombie Horde: creating an array of objects dynamically.
- `ex02` - HI THIS IS BRAIN: pointers and references.
- `ex03` - Unnecessary Violence: object composition with weapons.
- `ex04` - Sed is for Losers: file input/output and text replacement.
- `ex05` - Harl 2.0: pointers to member functions and dispatching behavior.
- `ex06` - Harl Filter: control flow based on severity levels.

## Usage

Build the exercise from inside its folder and run the generated executable. For example:

```bash
cd ex04
make
./replace
```

Some exercises are interactive or rely on file arguments, so read the subject and test with several inputs.

## Concepts Covered

- Dynamic allocation with `new` and `delete` teaches you to manage heap memory explicitly.
- References and pointers show how to access and modify data without copying it.
- Stack and heap lifetime explains why object ownership matters across scopes.
- Member function pointers let one object select behavior at runtime.
- File streams are used to read and write files safely and predictably.
- Simple control flow and parsing are used to route behavior based on text or numeric input.

## Build

Each exercise has its own Makefile. Build with:

```bash
make
```

Clean with:

```bash
make clean
```

## Tips

- Be strict about ownership when using dynamically allocated memory.
- Check input and output behavior carefully in the file exercise.
- Keep the code small and explicit; the subjects usually reward clarity.
