## Pointers: 
- Compound type that points to another type. 
- It is an object, unlike references. 
- Example for declaring a pointer: ``` int *ip1,*ip2; double dp, *dp2; // here, dp2 is a pointer to double but dp is a double. ``` 
- Taking the address to an object: ``` int ival = 42; int *p = &ival; // p holds the address of ival; ``` 
- A pointer can point to an object, the location immediately past the end of an object, or a null. 
- pointers can be used as a condition, inside if statements. For example, if a pointer is pointing to a value of 0/null, the condition evals to false. Otherwise, true. 
- void * pointers are pointers that can hold memory of any object. 
## Const qualifier 
- local to file by default - use 'extern' keyword to share const object among multiple files. for e.g.: `extern const int bufSize = 10;` 
- const reference to a non-const variable is legal. 
- int * const ptr = &a; // here, ptr is a const pointer. (referred to as the top-level const) 
- const int * ptr = &a; // here, ptr is a non-const pointer pointed to a constant. (referred to as the low-level const) 
### Constant expressions and constexpr 
``` 
const int max_files = 20; // max_files is a constant expression 
const int sz = get_size(); // sz is not a constant expression 
``` 
- constexpr makes sure that the const variable holds only a const expression. 
- example: `constexpr int mf = 20;` 
- constexpr can only hold literal types and not things like std::string types. This is because it requires compile-time evaluation 
- `constexpr int * q = nullptr; //here, q is a const pointer (not a pointer to a const)` 
## Type aliases 
- typedef double wages; // here, wages is a synonym for double 
- typedef wages base, * p; // here, base is a synonym for double and p for double* 
- modern c++ also uses the 'using' keyword for type alias declaration 
## auto type specifier 
- Used to let the compiler deduce the type of the variable. 
- it always drops the top-level const but keep the low-level const. 
## decltype specifier 
- used to define a variable with a type that the compiler deduces from an expression. 
- for example: `int ci = 10; decltype(ci) x;` 
- Here, x is of type int due to ci being evaluated to int - sometimes can yield a reference type. 
- for example: `int * p = &i; decltype (*p) c = &abc;` 
- Here, c is a reference type 
- decltype((ci)) will yield int& whereas decltype(ci) will yield int due to the parentheses 

-> In c++ classes and structs are used to define our own datatypes. The library types like the string, istream and ostream are all defined as classes.

-> an address refers to a byte in memory