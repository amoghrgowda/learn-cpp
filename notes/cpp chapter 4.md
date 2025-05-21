- Operator overloading means to give alternative meaning to existing operator symbol, such as for << or >>.

## Lvalues and Rvalues
- every expr is an rvalue or an lvalue.
- roughly speaking, rvalue returns the value of the object (its contents) and lvalue returns the object's identity (location in memory).
- except for one instance, we can use an lvalue when rvalue is required but not vice-versa

 ****Rule of thumb**** : When writing a compound expression, don't use the same operand elsewhere in the expr if you are changing it. Use parenthesis if you are unsure about the order of evaluation, precedence or associativity.
- negative of a true value returns true because true is represented as 1 and -1 is also true because it is non-zero.
- precedence of postfix operator is higher than dereference. Therefore, * ptr++ defaults to * (ptr++).
- Most operand give no guarantee for the order of evaluation. For example: `*beg = toupper(*beg); *(beg+1) = toupper(*beg);`

## Type cast
- Named casts has the form: `cast-name<type> (expression);`
### Static cast:
- Used when larger arithmetic type is assigned to smaller type. It informs the compiler and the reader that we are not concerned about loss of precision.
- ex: `void *p = &d; double *dp = static_cast<double*>(p);`
### Const cast:
- Converts a const object to non const type. This is the only way to change the constness of an expression, else it is a compile-time error.
- ex: `const char *pc; char *q = const_cast<char*>(pc);`
### Reinterpret cast:
- Used to reinterpret the bits of an object as another type.
- Converts between unrelated pointer types or between pointer and integer types.
- Not type safe.
- Interprets raw memory and used when working with hardware or embedded systems.
- ex: `int *ip; char *pc = reinterpret_cast<char*>(ip);`