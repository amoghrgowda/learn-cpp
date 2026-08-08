/*
This question requires you to complete the function splitString in the file Solution.cpp.

This function takes two arguments.

    A string s as the original string to be split.
    A non-empty string t is used as a splitting basis.

All the split substrings in order are formed into a vector<string> and returned using the return statement.

The evaluation machine runs main.cpp to call the splitString function in Soluction.cpp by importing a custom function library, and parses the contents of the returned string vector.
*/

/*
 * @param s: A string
 * @param t: A string
 * @return: A vector of sub strings
 */
vector<string> splitString(string &s, string &t) {

    vector<string> vec;

    int start = 0;
    int found = s.find(t);

    while(found != std::string::npos){ //npos is what is returned if nothing was found.
        vec.emplace_back(s.substr(start, found-start));
        start = found + t.length();
        found = s.find(t,start);
    }

    if(start != 0){ // this condition makes sure that vec does not contain an empty substring
        vec.emplace_back(s.substr(start));
    }

    return vec;
    
}