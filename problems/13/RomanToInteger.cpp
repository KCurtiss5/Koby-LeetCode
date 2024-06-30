class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        map<char, int> roman { 
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        for (int i = 0; i < s.length()-1; i++){
            if (roman[s[i]] < roman[s[i+1]]){
                sum -= roman[s[i]];
            }
            else {
                sum += roman[s[i]];
            }
        }
        sum += roman[s[s.length()-1]];
        return sum;
    }
};

/*
This is my naive approach. It goes through the string looking to see if the current letter is less than the next letter.
If it is, then it subtracts from the sum, otherwise it adds it. And then the last letter is ALWAYS added.

Runtime - 7ms Beats 75.33%
Memory - 12.66MB Beats 58.24%

Technically this solution is incorrect!!! Because of this part of the description:
There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.

However, this code will return 99 for IC despite IC not being valid. For 99, you need to write XCIX.
So lets fix that.
*/
