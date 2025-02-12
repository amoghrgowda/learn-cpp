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
