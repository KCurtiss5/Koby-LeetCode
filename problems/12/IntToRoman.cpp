class Solution {
public:
    string intToRoman(int target) {
        string ret;
        vector<int> ints = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < ints.size(); i++){
            while(target >= ints[i]){
                ret.append(roman[i]);
                target -= ints[i];
            }
        }
        return ret;
    }
};

/*
This is a pretty easy solution. We can place all of the possible letters in a list and then greedily build the string one sequence
at a time. This code isn't very maintainable, but since roman numerals aren't gonna be changing anytime soon, I think its okay.
Also we do change target here, since the function signature does not include const, so there's no guarantee that target won't
change.
Runtime - 3ms Beats 87.09%
Memory - 12.65MB Beats 38.29%
*/