class Solution {
public:
    string addBinary(string a, string b) {
        int a_index = a.size() - 1;
        int b_index = b.size() - 1;
        int carry = 0;
        string ret;
        
        while (a_index >= 0 || b_index >= 0 || carry) {
            int f = (a_index >= 0) ? a[a_index] - '0' : 0;
            int s = (b_index >= 0) ? b[b_index] - '0' : 0;
            int sum = f + s + carry;
            carry = sum / 2;
            ret.insert(ret.begin(), sum % 2 + '0');
            a_index--; b_index--;
        }
        
        return ret;
    }
};

/*
This is effectively the algorithm which ALUs use to add binary numbers. They start at the least significant unit, add the digits
and add in the carry digit. If you get 3, we return 1 3%2, if we get two, then our carry is still 1 but we insert a 0.

We just have to throw in some ascii magic. Since we're working with strings and integers, we need a few +- '0's. 

Runtime - 0ms Beats 100.00% O(N)
Memory - 8.24MB Beats 59.50%
*/