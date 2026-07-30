# compound types
C++ supports the following compound types:
- Functions
- Arrays (C-style)
- pointer types (to obj and func) 
- pointer to member (data mem and mem func)
- Reference types (l and r value)
- Enumerated types
- Class types - struct, classes and unions
# The value category of an expression
In C++, the value categories describes two properties in an expression: Does it occupy a recognizable and persistent place in memory? (**identity**) and Can it be stolen or moved safely because it is no longer needed? (**movability**).

The possible value categories are: lvalue, rvalue, glvalue, prvalue, and xvalue.
1. **lvalue** (locator/left value): It is an expression that resolves to an identifiable object or function (or a bit field). Its resources cannot be moved or stolen.
2. **rvalue** (right value): This kind of expression evaluates to a value which is not an **lvalue**. This includes literals (Except the C style string literals) and return value of functions that 'return by value'. It is an umbrella term for anything that can be moved from. Can be thought of as `rvalue = prvalue + xvalue`.
3. **prvalue** (pure rvalue): A temporary value used to compute something or initialize an object. It doesn't have an address you can take. For example, saying `a+b;` or `41`.
4. **xvalue**(expiring value): An object that _does_ have a memory address, but its resources are explicitly marked as safe to recycle/steal because it is expiring. Eg: `std::move(x);` - This casts 'x' to be an xvalue and enables move semantics.
5. **glvalue** (general lvalue): Think of it as `glvalue = lvalue + xvalue`. It is an umbrella term for anything with an identity in memory, regardless of whether the memory can be moved or stolen. **lvalue** is a type of glvalue which has a memory address but the resources CANNOT be moved.
# references
- References are just an alias to an existing object.
- References themselves aren't objects and do not occupy memory space. The compiler will usually replace the reference with the referent for optimization.
- 'Reference variable' is a misnomer because a variable occupies space. 
- It is not possible to have a reference to a reference.
- It is an lvalue that can only be bound to a modifiable lvalue.
- Surprisingly, a const reference can be bound to an rvalue.
# pointers
- The address-of (&) operator looks very similar to the AND operator. The difference is latter is a binary operator. We give preference to the binary operator over unary and that is why `X & Y` is read as X AND Y, not `X (&Y)`.
- The Dereference (`*`) operator is the opposite of the `&` operator.  The `*` operator says to get the object (value) at some specific address in memory, whereas the `&` operator says to get the address of a specific object (value).
- A **pointer** is an object that holds the memory address of another object as its value.
- `ptr` variable and `*ptr` both are an lvalue. But, the address-of expression `&x`, where `int* ptr = &x` , is an rvalue.
- The size of pointer depends on the architecture. On 32-bit systems, the size of the pointer is 32-bits. Similarly, on 64-bit architecture systems, the size of a pointer is 64 bits.
- The type of the pointer doesn't matter, pointers to any data type is the same size. The type is only specified for human readability and to prevent us from thinking there is a double at the memory of an integer type.
- Besides holding the memory address, a pointer can hold one more value - a null. 
- If we value initialize a pointer, it gets assigned a null and it becomes a null pointer.
- A nullptr implicitly converts to boolean value false and non-null pointer converts to boolean true.
## nullptr
- It is used in modern C++, instead of using `0` or `NULL` like in C.
- This is for safety issues where in certain function loading scenarios, passing in a `0` and `NULL` would call either a pointer parameter function or a integer parameter function with ambiguity. 
- To prevent this ambiguity (whether int* or int will be called), C++ introduced a different type for nullptr. 
- The type of nullptr is `nullptr_t`. `nullptr_t` can only hold one value -- a nullptr.
- Therefore, this is the only valid value the variable 'a' can have here: `std::nullptr_t a = nullptr;`
- To use `std::nullptr_t`, we should include `cstddef` library/header into the program.
- This was a deliberate choice so as to prevent the addition of a new keyword besides nullptr.
- Thus, we cannot access the type `nullptr_t`, without including the respective header (unlike `int`,`float`,`bool`,etc).
- `nullptr` itself is baked into the compiler and fully recognizable **keyword**. Therefore, we can use `decltype(nullptr)` if we don't want to include and use the nullptr_t type directly.
>[!note] 
>C++ essentially makes a copy of the address and pass it as an argument, when we use `pass by reference`. Therefore, no matter what method we use (pass by reference or pass by value), under the hood, C++ still makes a copy of the pointer, making it a 'pass by value'.

>[!note]
>C++ standard does not specify whether a reference will take memory space or not. Sometimes, it might. Especially, when the compiler cannot know the referenced object at compile-time, It needs to create an actual pointer to store the reference. Otherwise, its 0 bytes (if it can be determined at compile-time).

- non-const lvalue references are not allowed to bind to a temporary/rvalue object. This is because, if an `int` argument is passed to a `long&` parameter, implicit conversion will take place and a new object will be created for the long parameter, leaving the original reference unmodified by the function.
- Type deduction drops the reference, just like it does with `const`. If we want the type deduction to keep the reference, we need use `auto&`.
- `const int&` means that it is referring to a const int type, not that the reference is const. References are const by definition anyway.
- When deducing the type of the reference, the reference is dropped. But, when deducing the pointer, the pointer is not dropped. This is because, reference is always to a referred object value so it makes sense that the type deduced is that of the referenced object.