class Solution {
public:
    int reverse(int x) {
        long rev = 0;
        while (x != 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        if (rev > INT_MAX || rev < INT_MIN){
            return 0;
        }
        return rev;
    }
};

/*
Uses a nice little algorithm to reverse either negative or positive numbers correctly. It works on the decimal system, adding the
last number in x first, then moving everything over a decimal point by multiplying it by 10. Then it gets the next number in x by
dividing it by 10. Now there are some issues with reversing where a reversed integer can sometimes overflow. So I just used a long,
and if it did overflow, we return 0 like the problem specified.
Runtime - 0ms Beats 100.00% of users with C++
Memory - 7.44MB Beats 52.06% of users with C++
*/