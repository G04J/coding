# Bit Manipulation

A collection of bit manipulation algorithms and techniques implemented in various programming languages.

## Overview

Bit manipulation is the act of algorithmically manipulating bits or other pieces of data shorter than a byte. This repository contains common bit manipulation operations and their implementations.

## Common Operations
[bitwiseOperators.cpp](bitwiseOperators.cpp)
## Bitwise Operators in C++

| Operator | Name           | Description                                     | Effect |
|----------|----------------|-------------------------------------------------|--------------------------------|
| `&`      | AND            | Sets bit if both bits are 1                     | Keeps common set bits |
| `|`      | OR             | Sets bit if either bit is 1                     | Combines set bits |
| `^`      | XOR            | Sets bit if only one bit is 1                   | Toggles differing bits |
| `~`      | NOT (Negation) | Inverts all bits (two's complement)             | Flips all bits |
| `<<`     | Left Shift     | Shifts bits left (multiply by `2^n`)            | Moves bits left, filling with 0s |
| `>>`     | Right Shift    | Shifts bits right (divide by `2^n`)             | Moves bits right, discarding or extending sign bit |


## Key Techniques

1. Set a bit
2. Clear a bit
3. Toggle a bit
4. Check if bit is set
5. Count set bits
6. Find most/least significant bit
7. Power of 2 check
8. Odd/Even check

## Usage Examples

```cpp
// Check if number is even/odd
bool isEven = (n & 1) == 0;

// Multiply by 2
int multiply = n << 1;

// Divide by 2
int divide = n >> 1;
