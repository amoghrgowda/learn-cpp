# Strings in C++
- We needed to fix the messy and unpredictable C-style string.
- `std::string` gives us the easiest way to work with a string variable.
- lives inside the `#include <string>` header.
- `std::getline()` is used to read a full line of input because `std::cin` does not read a whitespace. example usage: `std::getline( std::cin >> std::ws, string_a);`
- `std::ws` is an input manipulator that tells  `std::cin` to ignore the leading whitespace.
- To get the length of a string, use `string_name.length()`. In documentation, it is listed as `std::string::length` because length is a special function belonging to std::string.
>[!best-practice]
>Never return a std::string by value because it is an expensive copy. Use std::string_view instead.
- std::string supports **move semantics**, which allows the object to be destroyed at the end of function to be returned by value, instead of making a copy. Put simply, move semantics is **transfer of ownership**.
- we can also create strings that do no stop while encountering a `\0` (null) by using this syntax: `std::string {var_name, count};`. Example: `std::string {"A\0B", 3};` will output `A\0B`, instead of  just `A` traditionally. 
>[!note]
>`std::string::length()` returns a unsigned value. Use `std::ssize()` to get signed value for the length instead.

>[!caution]
>`std::string_view` can lead to a dangling reference 

