- local variables (variables inside a function) are also called automatic variables because they have an automatic lifetime (destroyed at the end of the function scope).
- variables with static duration (including global variables) are also called **static variables**. 
>[!best-practice] 
>Use 'g_' for global variable names as convention to separate it from other variables.
- Translation unit is the largest piece of source code that C++ compiler processes in a single pass, to create one object file. In short, it is the source code + all `#include`s in the source file.
- non-const global variables are `extern` by default.
- When `static` keyword is applied to a global identifier, it becomes internally-linked.
- Using `static` keyword on a local variable turns its duration to static (just like a global variable). The only difference between global and static local variable is that latter has internal linkage and former has external linkage. Also, the scope differs ofcourse.
- `static` local variables are zero-initiallized.
# Halt functions
- `std::exit()` is called after `main()` is completed implicitly, with return value from main function passed as argument to `std::exit()`.
- `std::exit()` terminates the program immediately. To prevent that, we can use `std::atexit()` to cleanup some resource before termination.
# Algorithms
- A finite sequence of instructions that can be used to solve a problem or produce a useful result.
- An algorithm is considered **stateful** if it retains some information across the calls.
- An algorithm is **deterministic** if it produces the same results every time we give it the same input.
>[!note]
>A sentinel value is a value that has a special meaning for our function or algorithm.
# Error handling and debugging
- Instead of writing an error message after writing an if-else conditional every single time, C++ give us the `assert()` function.
- To use `assert()`, we need to `#include <cassert>`. `<cassert>` is essentially just a pre-processor macro. This is done to avoid large overhead of calling a function everytime. Although, `assert()` does come with a small overhead each time, it is not significant and will not affect the production code anyways.
- To disable the `assert()` statements, we need to write `#define NDEBUG` at the beginning of our program. This will instantly disable all the assert statements without having to manually remove each one.
- C++ has another type of assert called `static_assert`. A **static_assert** is checked at compile-time instead of run-time. `static_assert` is a keyword and hence, we do not need to include any preprocessor macro.
## Assertion vs error handling
- These are related and similar concepts so they can be confused. Assertion is used when the fault is programmer's fault and unacceptable and therefore, there is no recovery needed from it because they are meant to be stopped in the first place.
- Error handling, on the other hand, is used when the errors can happen during usage/run-time and needs to be gracefully handled. They can be recoverable (where program can keep running) or non-recoverable (where the program has to shut down but we can cleanup properly before shutting down and show convenient error message).