# Functions
- Functions in C++ cannot be defined inside another function. Nested functions aren't supported in C++.
- status code of 0 means the function ran normally (by convention).
- failure to return a value from a value-returning function will lead to an undefined behavior.
- Sometimes, we use unnamed parameters like `void do_something(int){}`. This is used in cases where our parameter count has changed (from 1 to 0 in this case) but we don't want to break other calling functions.
- If an anonymous object (temporary object) is used, it is stored only for that brief moment and usually has a very short scope (except when it is referred to). They are destroyed at the end of full expression or at the end of lifetime extended to match the reference.
- **Forward declaration** is used when we want to define the function at a later stage than be used ,i.e., before the main() function.
## Uses of a function
1. Organization
2. Reusability
3. Extensibility
4. Abstraction
5. Testing
# Intro to preprocessor
- The `#include` directive will be processed by a preprocessor.
- Preprocessors used to be separate tools before but in modern compilers, they are built-in
- When the preprocessor is finished processing a file, the result is called a **Translation unit**.
- The preprocessor doesn't understand C++ syntax. it has its own syntax. 
- It scans through the entire code to find a directive.
- `#include` is almost exclusively used to include a header file.
- We can use a preprocessor as a comment using `#if 0 ... #endif`.
>[!note] 
>If a macro is used within another directive, a macro-substitution does not occur.
# Header files
- Instead of having to manually list down every forward declaration in multiple files calling the functions, we can place all the forward declarations into one single file called a **header file (.h or .hpp)**.
- Although we can technically `#include` a `.cpp` file, we should avoid doing that because it can cause naming collisions, Any change to included .cpp file will mean having to recompile both the included and the main cpp files.
- We use the name of our custom header file with double-apostrophe, instead of an angle (<>) bracket. This is because angle brackets denote that the header file is present in a location where compiler/OS headers are located.
>[!note]
>`iosteam` and `iostream.h` are different header files! `iostream.h` is meant for old C++ programs, which did not know about the std namespace because it did not exist yet.
- If we decide to place the header files elsewhere other than current directory, we can compile it using the command `g++ -o main.cpp -I./relative/path/to/header` or `g++ -o main.cpp -I/full/path/to/header`.
- If one or more header files are included by the header file explicitly included by us, those header files are called **transitive includes**. It is always better to include explicitly than transitively.
>[!best-practice]
>It is better to include the header files alphabetically so that if a header is missing or needs to be verified or searched for, it will be easy to do so.
# Header guards
- To prevent transitive includes, we use header guards such as `#ifndef XYZ_H`, `#define` and `#endif`.
- One drawback of traditional headerguard can be understood with this example:- suppose two separate .cpp files such as `main.cpp` and `calc.cpp`, both are including a header file called `square.h`. The compiler will run fine because the `#ifndef` scope ends within `main.cpp` and a new scope starts in `calc.cpp`. Therefore, two copies are created of the header. In this case, though the compiler passes it, the linker will complain due to the clash/repetition. 
## Solution to the drawback of header guards - `#pragma once`
- Although it is not defined by the C++ standard, `#pragma once` ensures that a header is only included once.
- There is one instance where even `#pragma once` fails:- if multiple copies of the same header files exist in the system and they both get linked somehow, then, pragma won't prevent it, because it doesn't scan the contents.