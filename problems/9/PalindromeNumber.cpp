#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        while (num.size() > 1){
            if (num[0] != num[num.size()-1]){
                return false;
            }
            num = num.substr(1, num.size()-2);
        }
        return true;
    }
};

/*This is my first solution. Just turning the number into a string, then progressively checking whether the first and the last
number is equal. Then it cuts down the string by chopping off the first and last number until it either finds an instance where its
not a palindrome, or theres 0 or 1 numbers left. In which case, it is a palindrome and we return true.

Runtime - 7ms Beats 72.25%of users with C++
Memory - 10.48MB Beats 11.28%of users with C++

But there's a better way!
Let see if we can keep using integers and use a bit operation!
*/

class Solution {
public:
    bool isPalindrome(int x) {
        int rev = reverseNum(x);
        return !(x^rev);
    }

private:
    long reverseNum(int x){
        long rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
};

/*
This time, we avoid strings altogether. We can use the algorithm from question 7 to reverse the number, but this time we keep it
as a long (it needs be a long because not all reversed integers are valid integers). Then we can do a XOR comparison. If the 
XOR returns a 0, then they are equal. If it is anything else, then they are not equal. However, to return this as a boolean, we need
to flip it. Its true if its 0, and false if its anything else. This beats my previous code.
Runtime - 4ms Beats 84.63% of users with C++
Memory - 8.16MB Beats 78.96% of users with C++
*/
