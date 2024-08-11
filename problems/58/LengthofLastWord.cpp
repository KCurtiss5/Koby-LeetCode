class Solution {
public:
    int lengthOfLastWord(string s) {
        regex last_word("(\\w+) *$");
        smatch word;
        regex_search(s, word, last_word);
        return word.str(1).size();
    }
};

/*
My first thought when dealing with strings was regular expressions! So I wrote a quick regex search that matched the last word
and any whitespace after it. I set a capture group (which is why I have word.str(1)) to capture only the word and not the spaces.
However, for a problem like this, I think we can do a little better. Regex is not very readable.

Runtime - 533ms Beats 46.23% O(N)
Memory - 13.57MB Beats 5.10%


You can see that this algorithm is O(N). Regex will always start parsing from the start. So its not very efficient nor is it readable.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for (int i = s.size()-1; i >= 0; i--){
            if (s[i] != ' '){
                length++;
            }
            else if (s[i] == ' ' && length != 0) break;
        }
        return length;
    }
};

/*
This solution is a bit easier to read. We start reading the string backwards. If we see a space, we do nothing. The moment we start not
seeing spaces is when we start incrementing the length. And the moment we see a space after we've seen characters, we break.
This is also O(N) as worst case, but much much better average case.

Runtime - 0ms Beats 100.00% O(N)
Memory - 7.82MB Beats 46.74%
*/