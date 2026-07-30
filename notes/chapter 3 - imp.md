# Data types
## Bits, bytes and memory addressing
- When a variable is defined, a piece of RAM is set aside for it.
- The smallest unit of memory is bit but in C++, we typically deal with bytes (common in modern computer architectures).
## Data types in C++
- float (>=6 decimals - 4 bytes), double (>=10 decimals - 8 bytes), long double (varies -> on linux, 16 bytes)
- bool (1 byte) - a real bool type.
- char (1 byte, including unsigned or signed char), wchar_t (varies ->4 bytes on linux), char8_t (1 byte), char16_t (2 bytes), char32_t (4 bytes).
- short int (varies -> 2 bytes), int (varies -> 4 bytes), int8_t (1 byte), int16_t (2 bytes), int32_t (4 bytes), int64_t (8 bytes), long int (varies -> 8 bytes), long long int (varies -> 8 bytes),  -- uint, uint8_t, uint16_t, etc are all same as int counterparts.
- std::nullptr_t (varies -> typically 8 bytes), std::size_t (guaranteed to fit a pointer -> 8 bytes)
- void (implementation defined but usually 1, sometimes 0..but could be anything)
- pointers (4 bytes on 32-bit or **8 bytes** on 64-bit)
- The above types can be determined using a `sizeof()` operator.
>[!note]
>long int and long long int are both same size because linux and Mac follows LP64 = Long int and pointers are 64-bit, when transitioning to 64-bit architectures.
- void is an **incomplete type**. Meaning, the compiler knows about it but does not have the information about how much memory to allocate to it.
- Note that C++ only guarantees that int will be of some minimum size, not that they will be guaranteed a size.
- `intx_t` was introduced to fix the variable size of `int` data types. They belong to the `std` namespace and hence it is recommended to always use `std::int8_t`, even though on specific compilers it will work without std namespace.
>[!note]
>the 8-bit fixed integer behaves like a char data type and trying to print `int8_t x = 65;` might print `A`.
- These fixed width integers aren't new data types, they are simply aliases for existing types. For example, on systems where int is 32-bit, `int32_t` will just translate to `int`. `int8_t` resolves to simply a `signed char` . This is the reason for the above note.
>[!note]
>Some CPUs maybe faster in processing `int64_t` than `int32_t`. Why? Because some ALUs maybe built around the 64 bit primary data path and 32 bit values would need to be sign-extended or zero-extended to 64-bit.
- `std::int_fast32_t` will give the fastest signed int type that can hold atleast 32 bits (or 8 or 16, etc whatever is specified instead of 32). 
- `std::int_least32_t` will give the smallest int type that is atleast 32 bits (or 8 or 16, whatever is specified instead of 32).
>[!best-practice]
>Avoid the fast and least types because they behave differently on different systems.

>[!best-practice] Summary to remember always
>- prefer `int` when the size doesn't matter.
>- prefer `std::int#_t` to get a fixed range.
>- Avoid: `long` and `short`, 8-bit fixed int types, fast and least int types
- When we use the `sizeof()` operator, it returns a `std:;size_t` type. `std::size_t` is actually a typedef.
- The size of `std::size_t` depends on the implementation architecture - 32 bits or 64 bits unsigned integer. It should be able to hold the size of any data type because, after all, `sizeof()` depends on `std::size_t` to return the size of a data type.
### Bool
- C++ has a real boolean data type.
- A function with boolean return type will return `true` or `false` only.
- Boolean types during I/O operations (and storage purposes) are considered to be `1` (for `true`) or `0`(for `false`). This is for performance and C-compatibility reasons. It is much faster to handle a predictable 1 or 0 in I/O (takes exactly 1 byte), instead of using true or false strings (taking 4 or 5 bytes).
- To ensure it inputs and outputs only true and false, use `std::boolalpha`. To turn it off, use `std::noboolalpha`.
### Char
- Uses ASCII representation for numbers from 0 to 127.
- ASCII 97 = 'a'. ASCII 65 = 'A'.
- It stores characters as int in memory for the same reasons bool does it.
### Type conversion
- Usually, converting a type (such as int to float) does not change the type of existing value, it returns a new value of desired type instead.
- Some advanced casts such as `const_cast` or `reinterpret_cast` do not return temporary objects. They reinterpret the type of existing value/object.
- For type casting, use `static_cast<type>(expression);`. Eg: `static_cast<int>(5);`