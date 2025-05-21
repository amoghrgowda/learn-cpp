--> This is a very simple and small chapter about Statements so I skip most of the notes.

- It is legal to initialize a variable within a case1 block and then use that variable case2 block. But assigning a value to the variable within case1 block directly is illegal. For example: 
```
case true:
	string file_name = 0; //illegal
	int jval; //legal
	break;
	
case false:
	jval = next_num(); //legal
```

## try and Exception handling
- Exceptions are run-time anomalies that exist outside the normal functioning of a program (such as losing a database connection or unexpected input).
- Exception handling is used when one part of the program detects a problem that it cannot resolve.
- `try` is the block inside which an exception might occur.
- if an error occurs inside the `try` block, an exception is raised using the `throw` keyword.
- `catch` block is used to catch the exception and it is a way to recover from the error. They are also called as `exception handlers`.
### Standard exceptions
- Standard exception classes are defined in `<stdexcept>` header.
- `exception` is used for the most general kind of problem.
- `runtime_error` is used for problems which can be detected only at run time.
- `range_error` is a run time error generated outside the range of meaningful values.
- Other standard exceptions include: `overflow_error`, `underflow_error`, `logic_error`, `invalid_argument`, `length_error`, `domain_error` and `out_of_range`.