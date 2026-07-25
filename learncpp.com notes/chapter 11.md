# Program-defined/ User-defined types
- The compound types that are used to create user-defined types are Enumerated types and Class types.
- User-defined type definitions always end with a semicolon.
- Convention to name a user-defined type is to start with a capital letter and do not end with any suffix. Example for valid convention: `Fraction`. C++ is case-sensitive.
>[!best-practice]
>A program-defined type used in only one code file should be defined in that code file as close to the first point of use as possible.
>
>A program-defined type used in multiple code files should be defined in a header file with the same name as the program-defined type and then `#included` into each code file as needed.
# Enumerations
- There are two types - Scoped (class enum) and Unscoped enumerations.
- We can put enum inside a namespace so that one `enum` element does not collide with another enum's element.
- A scoped enum (also called `enum class`) prevents implicit integer conversion and prevents name collision even without a namespace.
- Each element is implicitly assigned integer values like 0, 1, 2, etc. consecutively by default.
- The elements can share explicitly assigned integer values and these values can be negative too.
- It doesn't matter whether the enum contains 1 option or 2000 options, it will still occupy the space of 1 integer. We can also explicitly state the size of the enum, such as: `enum Color: std::int8_t`.
- The enum definition itself occupies 0 bytes (no memory). It is simply a blueprint for the compiler to assign a value when we start using a type instance.
- We can also assign a preferred value of our own to each enum element. Such as:
```
enum StatusCode{
	OK = 200,
	NotFound = 404,
	ServerErr = 500
};
```
- Trying to print the value of an enumerator element will print the default or initialized value (integer).
- To print the name of the enum element, we usually use a function implementing a switch-case that does this job.
- While enum can be implicitly (only unscoped because scoped requires explicit conversion only) converted to an int, vice-versa is not true. We can achieve this through static casting.