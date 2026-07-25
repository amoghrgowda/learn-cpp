# Constants and Strings
## Constants
- To define a constant, a `const` keyword is used.
- `const` can be placed either before (conventional) or after (east-const). For example: `const int a = 5;` or `int const a = 5;`. The conventional is the best practice.
- We can define a constant using a non-const variable, such as `const int b {a};`.
- Const variables **must** be initialised.
- Do not return a const from a function. The return variable is temporary anyway.
## As-if rule and compile-time optimisation
- A profiler is the program used to see how long various parts of the program take to run
- Optimisation involve some trade-offs and this is why compilers support multiple optimisation levels.
- The **as-if** rule states that the compiler can modify the program however it likes , so long those modifications do not affect the program's "observable behaviour".
#### Compile-time optimisation
- Modern C++ compilers are capable of fully or partially evaluating certain expressions at compile-time rather than run-time.
- Some of the compile-time evaluation techniques are:
	1. Constant folding: replaces expressions with the the results. For example 1+3, with 4.
	2. Constant propagation: replaces the known variables (which doesn't seem to change their value) with their values. This prevents storing in memory and reading from memory (2 operations).
	3. Dead code elimination: Removes code that maybe executed but has no effect on program's behaviour.
## Constant Expressions
- We need to note that expressions evaluate at runtime.
- But under the as-if rules of the compiler, the expression might be compiled during run time or compile time, depending on whether the compiler requires input from user or not.
- Constant expressions are the backbone of compile-time evaluation in C++. 
- A constant expression needs to be evaluated at compile-time (just a suggestion to the compiler and not compulsory in case of functions), denoted by `constexpr`.
- **Definition**: It is an expression that must be evaluatable at compile-time.
- An expression that is not constant, maybe informally called a run-time expression.
- If a variable is not a const or does not have a integer literal (eg. 5.2) or the initializer is not a constant expression, then the variable cannot be used in a constant expression
>[!note] 
>Constant expressions have been designed such that they do not compulsorily need to be evaluated at compile time by the compiler, partly because forcing compile-time-only evaluation would make debugging very difficult
- E.g: `const int a = 5.0;` is not a const expr, `const int a{};` is a const expr, `const char a {'q'};` is a const expr.
### The `constexpr` keyword
- Just the keyword `const` can not guarantee that the variable is usable in a constant expression. `const` also does not extend to non-integral variables.
- `const` means the variable is constant and does not change throughout the program. `constexpr` means that the variable can be used in a constant expression. eg: `constexpr double a {5.0};`.
>[!best-practice]
>Any constant variable whose initializer is a constant expression should be declared as `constexpr`.