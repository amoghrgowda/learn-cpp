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
- enums are constexpr and therefore, cannot hold values that are non-constexpr.
# I/O operator overloading
## overloading `<<` operator
- `std::cout`, `std::cerr`, etc have the type `std::ostream`.
- This ostream type is by-default able to handle all the standard types but not user-defined types.
- This is where overloading is helpful. 
# Aggregates
- In C++, an aggregate is a type that can contain multiple data members.
- There are only 2 aggregates in C++: Arrays and class types (struct, union and class).
# Structs
- If only some data members are value initialized, The remaining uninitialized members are also value-initialized.
- For example: 
```
struct Employee
{
    int id {};
    int age {};
    double wage { 76000.0 };
    double whatever; // will be initialized to 0.0
};
```
- For **designated initialization**, we can use the dot operator like so:
  ```
  struct Foo
{
    int a{ };
    int b{ };
    int c{ };
};

int main()
{
    Foo f1{ .a{ 1 }, .c{ 3 } }; 
    Foo f2{ .a = 1, .c = 3 };  

    return 0;
}
  ```
  - A designated initialization is good practice because it is self documenting.
>[!best-practice] 
>For structs, always provide a default value for the members. Always use list initializers for instantiating rather than default initialization alone.
- The size of a struct cannot be guaranteed. We can only say that the **MINIMUM** size will be the sum of all the data members of the struct, due to padding.
- Padding is added by the compiler for optimization purposes (see data structure alignment for info).
>[!note]
>To minimize the padding, we have to define the members in the decreasing order of their sizes. Compiler is not allowed to do this. Therefore, it has to be done manually.

>[!best-practice] always use `->` operator instead of a `.` for pointers to struct objects.
# CTAD (Class Template Argument Deduction)
- C++ deduces the type of the template automatically, by looking at the arguments.
- But, we should not specify any angle `<>` braces or a type of even a single argument. It will result in a compilation error.
- Example: `std::pair p1 {5, 15};` is valid because it will deduce the type of pair to be int.
- If we had written it as `std::pair<> p1 {5, 15};` it would be an error.
- CTAD doesn't work inside a class-type because we cannot use CTAD on a non-static member initialization.
- CTAD also cannot be used inside a function parameter.