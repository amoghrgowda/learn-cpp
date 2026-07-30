# Function overloading resolution
- When a function isn't overloaded and we pass arguments, they types of parameter and arguments directly match, or the compiler tries to implicitly match, or there is a compilation error.
- What happens when functions are overloaded and there isn't an exact match? For example, for `add(int)` and `add(double)`, we pass in `add('A')` or `add(5L)`? This is called overloading resolution. (spoiler: the 5L example will lead to a compilation error because numerical promotion cannot occur for a `long` to match int or double).
- For functions where we want to explicitly stop the numerical promotion, we should use the `delete` keyword. For example: `void add(char) = delete;`.
# Default argument
- Example: `int add(int a = 5, int b = 10){}`.
- Remember that default arguments cannot be re-declared. For example, after the above declaration: `int add(int a = 10, int b)` is a compilation error.
- The default arguments usually go in the forward declaration.
# Function Templates
- It is a function-like definition that is used by the compiler to generate one or more overloaded functions (as per requirement).
- The initial function template used to generate all the remaining ones is called the **primary template**, and the functions actually generated are called **instantiated functions**.
- The placeholder types in templates are informally called the **template types**.
- C++ supports **3** kinds of template parameters - Type template, Non-Type template (such as a constexpr or a literal, and Template template parameter.
## Function template instantiation
- If we explicitly state the type of the function template instance, this **process** is called **instantiation**.
- The function instantiated from a template is called a **specialization**, and the template itself is called a **primary template**.
- When calling/instantiating a template function by, for example, `max()`, both the template and non template functions will be considered, and if both results in the same thing, then the non-template function will be preferred.
- In such above cases, if we want to force the compiler to use the template (instantiated) function, we should call `max<>();` instead of just `max();`
- We can tell the compiler that certain instantiation should be disallowed using the `delete` keyword. For example: 
```
template<>
const char* addOne(const char* x) = delete; 
```
- Function templates can also have default values, just like the normal functions.
>[!note]
>type conversion is only done to resolve function overloading, not when performing template argument deduction. That is why, we cannot use `typename T` for both arguments for a template that is expected to take two different argument types like `(int a, double b)`.
- If we want to forward-declare a template function, we must use a **Trailing Return Type** to specify the return type.
- In C++, if we use the `auto` keyword for the arguments while defining a non-template function, the compiler automatically turns the non-template function into a template function. This is known as **Abbreviated function templates**.
- Function templates can themselves be overloaded.
- For example:
```
template <typename T>
auto add(T x, T y)
{
    return x + y;
}

template <typename T, typename U>
auto add(T x, U y)
{
    return x + y;
}
```
- When are non-type template parameters useful? When we need to pass in a constexpr parameter (for operations like static_assert for efficiency instead of `assert()` which runs at runtime). Normal functions cannot take constexpr as parameters. This is because functions are built for run-time, while constexpr forces the compiler to resolve at compile-time.
- Template definitions **must** be placed in the header file so that it is copied to each and every .cpp file that uses it for constexpr, unlike regular function. Hence, it is possible to pass constexpr to template functions but not regular functions.
# constexpr functions
- These are functions with constexpr return type. 
- It simply means that these functions can be used in a constant expression.
- They may or may not be evaluated at compile-time, it is not a guarantee, unlike constexpr variables.
- We cannot forward-declare a constexpr function. It is supposed to be fully inline.