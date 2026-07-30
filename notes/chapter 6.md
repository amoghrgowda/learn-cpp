- Remember that precedence is to determine which operator to evaluate first. 
- Associativity is to determine how to evaluate a complex expression with same precedence operators.
- The GCC compiler evaluates the arguments of a function right-to-left. This varies from compiler to compiler.
## The remainder operator
- Also called modulo or modulus operator (%). 
- It gives an integer remainder, considering the left operand's sign only. 
- For example : `-9%4 = -2` but `9%-4 = 2` and also, `-9%-4 = -2`.
- Hence, it works differently than mathematics. This is why we should prefer to call it the remainder operator and not modulo (which refers to mathematics).
## exponent operator
- C++ does not have an exponent operator. The `^` is a XOR operator.
- Therefore, we include the `cmath` header and use `std::pow()` function.
## comma operator
- For example, `(x,y)` signifies to evaluate x, then y and return y.
>[!caution]
>using ternary operator will convert both the T/F results into matching types. For example: `true? -1 : 2u` will return an unexpected result because `-1` will be converted to unsigned int, which is not possible. If a matching type cannot be found, compiler will error.
