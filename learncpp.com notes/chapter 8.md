# Type conversion
- The data type size variability was allowed so that the `int` and `double` data types could be set to the size that maximizes performance on a given architecture. For example, a 32-bit computer will typically be able to process 32-bits of data at a time. In such cases, an `int` would likely be set to a width of 32-bits, since this is the “natural” size of the data that the CPU operates on (and likely to be the most performant). Atleast in some older CPUs, it hurts the performance to operate on narrow values because additional tricks are to be performed. In modern CPU architectures, it improves the performance.
- The size of int and double depends on which **data model** the compiler is following. Is it the LLP64 (Windows) = Long long and pointers are 64 bits or LP64 (UNIX systems) = Long and Pointers are 64 bits.
## Numeric promotions
- In cases where the CPU is not efficient on narrower data size, we need to perform a numeric promotion.
- It is value-preserving (safe) conversion. For example, a char to the size of an int or double.
- Two types of numeric promotions - Floating (decimal) point and Integral promotions.
- Different from numeric conversion (which is not guaranteed to be safe).
# Type casting
- There are 4 named casts and 1 C-style cast in C++.
- Named casts: static_cast, dynamic_cast, const_cast and reinterpret_cast.
## static_cast
- Performs compile-time type conversions between related types.
- syntax: `static_cast<data_type>(variable);`
- It performs direct initialization.
- We use static_cast to make narrowing conversions explicit.
## dynamic_cast
- Performs runtime type conversions on pointers or references in a polymorphic (inheritance) hierarchy.
- Example: A pointer to some parent class (say, Animal) can be casted to pointer to the derived class (say, dog).
- syntax: `dynamic_cast<type>(variable);`
## const_cast
- Used to add or remove the const qualifier.
- Use case: sometimes, we have a pointer to a const but is actually pointing to a non-const value. In such cases, it is safe to use this.
- Not recommended due to how unsafe it is. Only recommended to use it to add const qualifier.
## reinterpret_cast
- Reinterprets the raw, bit-level representation of one type as if it were another type.
- It is the most unsafe cast to use.
# Alias
- We can provide a different name (identifier) to an existing type so as to make it easier to read, write and give extra meaning.
- It can be done by using the `using` keyword.
- For example: `using a = double;`.
# Type deduction
- This is done using the `auto` keyword, where it deduces and assigns the type automatically from the provided information. Type information cannot be deduced from a function returning `void` or unassigned variable.
- `auto` is most useful when the type becomes very complex or hard to figure out manually.
- **Note**: `auto` drops the const qualifier when deducing the type. If we want to keep the const qualifier, we should provide it ourselves, for example: `const auto a {b};`.