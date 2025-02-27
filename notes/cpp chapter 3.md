-> strings, vectors and arrays.
- string and vector are abstractions of primitive array type. They are variable length sequence of characters and variable length sequence of objects respectively.
- the code inside headers should not include 'using' declarations, because the contents of the header are copied into the program's text.
## string type
- must include string header to use (`#include <string>`)
- example initialisation: 
```
string s1;
string s2 = s1; // s2 is a copy
string s3 = "hello"; // s3 is copy of string literal
string s4(10, 'c'); // s4 is cccccccccc
```
- the .size() doesn't return an int or an unsigned int. It returns a string::size_type
- Consider the following:
```
string str = "Hello";
string phrase = "Hello world";
string slang = "Hiya";
```
- Here, upon comparison, str < phrase < slang
- concatenation is done by adding different strings. Such as str + slang = "HelloHiya"
- remember that string literal and library strings are different.
### Dealing with characters in string:
- To process every character in the string, use a range for loop: `for(auto c: str){ statement; }`
- some cctype library functions are - isalpha, isalnum, iscntrl (for control char), isdigit, isgraph (not space and printable), islower, isupper, ispunct, isspace, toupper, tolower.
- There are two ways to processing only some characters in a string: subscript and iterator. Whereas, the range for loop is used when we want to process every single character in the string.
- the .size() function returns a type string::size_type (which is similar to unsigned int but is platform independent)

## Vector type:
- A vector is a collection of objects which have the same type. It is referred to as a container, as it contains other objects.
- It is a class template, not a type. Types generated from vector should include the type. For example: `vector<int>`.
- used to add elements at runtime. List initialization is valid only using curly braces. For example: `vector <string> v1{"a", "an", "the"}`.
```
- vector<int> ivec(10, -1); // 10 elem with -1 as value
- vector<string> svec(10, "hi!); // 10 elem with "hi!" as value
- vector<int> ivec1(10); //10 ele with 0 as value.
- vector<int> ivec2{10}; // 1 ele with value 10.
- vector<int> ivec3 {10,5}; // 5 ele with value 10.
```
### Adding elements to a vector:
 - we use a vector member named **push_back()** to add elements to vector. 
 - More performant to add elements at runtime than at compile time to a vector.
 - cannot use a range for loop to add elements to vector.

-> other vector operations include: v.empty(), v.size(), v.push_back(), v[n], v1 == v2, v1!=v2, <,<=,>,>=, v1={ }, v1 = v2.

### Iterators
- An **iterator** is an object that acts like a pointer to elements in a container.
- Used to access the elements of a container object (such as vector, array, lists, etc.) and string.
### Using iterators:
- Iterators contain members such as begin and end, accessed like this: `auto b = v.begin(), e = v.end();`
- * iter returns a reference to the element
- iter->mem fetches a member function just like (* iter).mem()
- ++iter, --iter, iter1 == iter2, iter1 != iter2 are some more operations.
- .end() returns an iterator pointing to something after the last element
- .cbegin() and .cend() are used for const_iterator type.
- to find the mid-point index in a container, do: `auto a = v.begin() + v.size() / 2;`
## Arrays
- int arr[4] can hold 4 elements, viz. arr[0], arr[1], arr[2], arr[3].
- Fixed size version of vectors.
- Better run time performance than vector. Use vector if you don't.
- The dimension of the array must be a const_expr.
- if the dimension is greater than the number of initializers, then default values are initialized to the remaining values (0 for int type, "" for char,etc.)
- when dealing with char arrays, always leave an extra space for '\0' (null).
- copy initialization is not allowed
- int * ptr[10]; is an array of 10 pointers.
- int (* ptr)[10] = &arr; is a pointer to an array of 10 elements
- subtracting two pointers like end(arr) - begin(arr) gives a library type named `ptrdiff_t`, similar to the `size_t`, it has machine-specific type.

--> multi-dimensional array is a contiguous memory in C++. They are just an array of arrays and strictly speaking, multi-dimensional arrays don't exist in C++.
