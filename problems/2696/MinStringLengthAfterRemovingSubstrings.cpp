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

class Solution {
public:
    int minLength(string s) {
        int i = 0;
        while (i < s.length()) {
            if ((i + 1 < s.length() && s[i] == 'A' && s[i + 1] == 'B') || 
                (i + 1 < s.length() && s[i] == 'C' && s[i + 1] == 'D')) {
                s = s.substr(0, i) + s.substr(i + 2);
                if (i > 0) --i;
            } else {
                ++i;
            }
        }
        return s.length();
    }
};

/*
This only loops through once! Saves a ton of time searching through the string. But if we're doing this, we can just use a stack!
Runtime- 19ms Beats 5.57%
Memory- 15.24MB Beats 5.05%
*/

class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (char c : s) {
            if ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D')) {
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.size();
    }
};

/*
This is the next logical step. Lets just use a stack instead. This is much faster.
Runtime - 6ms Beats 57.32%
Memory - 11.60MB Beats 31.24%
*/