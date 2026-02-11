# 🧩 CPP06 — C++ Casts and Type Conversion

Understanding C++ casting operators, type safety, and low-level data manipulation.

Welcome to **CPP06**, the seventh module of the 42 C++ Modules, focusing on type conversion and casting in C++. This module explores how data can be safely (and sometimes unsafely) converted between types, and how C++ provides powerful casting operators to control this behavior.

---

## 🚀 Project Overview

CPP06 emphasizes:

* Understanding scalar type conversion
* C++ casting operators (`static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`)
* Safe vs unsafe type conversion
* Runtime type identification (RTTI)
* Writing clear, controlled, and predictable type transformations

This module deepens your understanding of how C++ handles types internally and prepares you for more advanced object-oriented programming and polymorphism concepts.

---

## 📘 Exercises Overview

### ex00 — Conversion of scalar types

Implement a program that converts a literal into:

* `char`
* `int`
* `float`
* `double`

Handle special cases (`nan`, `+inf`, `-inf`, etc.) and display properly formatted output.

---

### ex01 — Serialization

Implement:

* A `serialize()` function converting a pointer into an integer type (`uintptr_t`)
* A `deserialize()` function converting it back into a pointer

Practice low-level casting using `reinterpret_cast`.

---

### ex02 — Identify real type

Create a base class with derived classes (`A`, `B`, `C`).
Use `dynamic_cast` to:

* Identify the real type of an object
* Handle failed casts safely

Demonstrate runtime type identification (RTTI).

---

## 🧠 Key Concepts Covered

* Scalar type conversion
* C++ casting operators:

  * `static_cast`
  * `dynamic_cast`
  * `reinterpret_cast`
  * `const_cast`
* Runtime Type Identification (RTTI)
* Polymorphism and inheritance
* Safe vs unsafe conversions
* Pointer manipulation

---

## 🛠️ Technologies

* **Language:** C++
* **Standard:** C++98
* **Compiler:** `c++`
* **Build:** Makefile
* **OS:** Linux

---

## 📦 How to Use

Clone the repository:

```bash
git clone https://github.com/Keillin-M/CPP06.git
cd CPP06
```

Compile an exercise:

```bash
make
```

Run an exercise:

```bash
./ex00
./ex01
./ex02
```

---

## 🧪 Challenges Faced

* Handling edge cases for scalar conversion
* Correctly formatting floating-point output
* Understanding when each cast type should be used
* Avoiding undefined behavior with unsafe casts
* Mastering `dynamic_cast` and RTTI

---

## 💡 Lessons Learned

* Type conversion must be explicit and controlled
* `static_cast` is safer than C-style casts
* `dynamic_cast` allows safe polymorphic behavior
* `reinterpret_cast` should be used carefully and intentionally
* Understanding casting improves low-level C++ mastery
* Type safety is critical for writing robust and predictable programs

