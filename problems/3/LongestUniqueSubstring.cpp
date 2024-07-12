class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        //sliding window
        size_t start = 0;
        size_t window_size = 1;
        while (start+window_size <= s.length()){
            if (validSubstring(s.substr(start, window_size))){
                window_size += 1;
            }
            else {
                start += 1;
            }
        }
        return window_size-1;
    }

private:
    bool validSubstring(const string& s){
        set<char> c;
        for (char letter: s){
            if ((c.insert(letter)).second == false){
                return false;
            }
        }
        return true;
    }
};

/*
This uses a set to check whether a substring is valid. However, the algorithm itself is simple. Its a sliding window algorithm
which uses the fact that we're only looking for the length of the longest. So what we can do is, take a "window" of letters that
is one higher than the longest known substring and check whether its valid. If not, then we can move one letter forward and check
again. Once we are at a place where the start+window_size is longer than the string, we can't have a longer substring, so we stop.
However, this is slow.

Runtime - 612ms Beats 5.03%
Memory - 277.25MB Beats 5.00%
*/