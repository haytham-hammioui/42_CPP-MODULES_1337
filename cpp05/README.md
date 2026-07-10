# CPP05

<h1 align="center">42_CPP05_1337</h1>

The `cpp05` module focuses on exceptions, validation, and error handling through a bureaucratic theme. The exercises are designed to make failure states explicit and controlled.

## Description

This module teaches how to structure code around preconditions, grades, permissions, and exception safety. It reinforces the habit of checking assumptions instead of letting invalid states spread.

## Exercises

- `ex00` - Bureaucrat: grades, limits, and validation.
- `ex01` - Forms: signing logic and exception handling.
- `ex02` - Advanced forms: execution constraints and polymorphic behavior.

## Usage

Build each exercise from its folder and run the binary to inspect the validation flow.

```bash
cd ex01
make
./bureaucrat
```

The important part is to check both success and failure cases, because this module is mostly about behavior at the boundaries.

## Concepts Covered

- Exceptions let a class report invalid states instead of silently continuing.
- Custom error types make failure modes clearer and easier to diagnose.
- Invariant checking ensures that grades, permissions, and object state stay valid.
- Boundary validation protects the class from values outside the allowed range.
- Copy behavior in exception-safe classes matters when forms or bureaucrats are duplicated.
- Polymorphic execution rules describe how a form decides whether it can be signed or executed.

## Build

Use the Makefile in each exercise directory:

```bash
make
```

## Tips

- Check both lower and upper bounds when validating grades.
- Use exceptions to report invalid states clearly.
- Keep your class invariants true at every public entry point.
