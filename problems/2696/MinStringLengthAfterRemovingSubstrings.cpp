class Solution {
public:
    int minLength(string s) {
        size_t pos;
        
        while ((pos = s.find("AB")) != string::npos || (pos = s.find("CD")) != string::npos) {
            s = s.substr(0, pos) + s.substr(pos + 2);
        }

        return s.length();
    }
};

/*
While, this is simple, its also super slow. It just uses find to search through the string to see if we have any instances of "AB" or "CD",
then if it finds one, it removes it and rinse and repeat. Simple solution, but bad in every way.

Runtime- 21ms Beats 5.05%
Memory - 15.40MB Beats 5.05%
This is super slow because find is looking through the entire string over and over again. Let's try something better.
*/