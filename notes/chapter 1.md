# Statements and function
## Statements
- A computer program is a sequence of instructions that tell the computer what to do.
- A statement is a type of instruction that performs some action.
- Types of statements are : Declaration statements, conditional statements, Jump statements, iteration statements, Try blocks, Expression statements and compound statements.
## Functions
- A function is a collection of statements that get executed sequentially.
- Every C++ program should have a function called main.
#  Intro to iostream: cout, endl and cin
- `std::cout` is buffered. We have to use `std::endl` to insert a new line and flush the buffer, otherwise, a new line for a new `std::cout` statement cannot be guaranteed. we can also use `std::flush` to simply flush, without adding a new line.
- Note: even though `\n` appears to be two characters, it is treated as a single LineFeed (LF) character (hence single apostrophe), with ASCII value 10.
>[!caution] 
>If you use `/n` instead of `\n`, you will create a multi-character character in C++, which will make the compiler 'combine' (place bits side by side) into a single integer. Hence, why `std::cout << '/n'; will often print as 12142`.
- cin is also buffered and the buffer stops reading when a whitespace or `\n` is encountered.
- if a character is entered when an integer input is expected, it is dropped from the cin buffer because int cannot hold a letter.
# Uninitialized variables and undefined behaviour
- In C++, variables do not generally have default values.
- The exceptions for defaults values are: Value Initialization (`{}`), default constructor initialized values, global variables, and static variables.
- value initialization is preferred to copy initialization. This is because `int x = 3.14;` is allowed (x becomes 3), but `int x{3.14};` throws error.
>[!note]
>function calls are a part of expression statements. Also, `cout << x;` is an expression statement because `<<` is a binary operator.

- C++ has 6 different kinds of initialisation:
	1. default initialisation: `int x;` 
	2. copy initialisation: `int x = 5;`
	3. direct initialisation: `int x(5);`
	4. direct list initialisation: `int x{5};`
	5. copy list initialisation: `int x = {5};`
	6. value initialisation: `int x {};`
- Both default and copy initialisation will be optimised exactly the same by the compiler. Only list initialisation blocks narrowing/rounding-off.