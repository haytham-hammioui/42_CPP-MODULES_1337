# CPP03

<h1 align="center">42_CPP03_1337</h1>

The `cpp03` module introduces inheritance and the first real class hierarchies. The goal is to understand how derived classes reuse and extend behavior from a base class.

## Description

This module focuses on inheritance, protected members, constructors, destructors, and the way behavior changes across a family of related classes.

## Exercises

- `ex00` - ClapTrap: the base class for the rest of the module.
- `ex01` - ScavTrap: extending the base class with new behavior.
- `ex02` - FragTrap: adding another derived class with different stats.
- `ex03` - DiamondTrap: multiple inheritance and shared base state.

## Usage

Build the exercise you want to test and run the resulting program.

```bash
cd ex03
make
./diamondtrap
```

The module is best understood by running the examples and watching how the constructor, destructor, and attack logs change across the hierarchy.

## Concepts Covered

- Inheritance allows a derived class to reuse the interface and behavior of a base class.
- Access specifiers control what the child class can see or change.
- Derived class construction and destruction show how the base portion and the child portion are initialized in order.
- Reusing and specializing behavior helps you avoid duplication while still customizing the class.
- Virtual destructors and base-class safety prevent cleanup bugs when objects are used through a base pointer.
- Multiple inheritance patterns are explored in the final exercise, where shared state must be handled carefully.

## Build

Build each exercise from its own folder:

```bash
make
```

## Tips

- Keep constructor and destructor messages consistent.
- Be careful with the base-class state when multiple classes share it.
- Read the subject order carefully; later exercises depend on earlier ones.
