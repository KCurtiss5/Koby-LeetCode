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