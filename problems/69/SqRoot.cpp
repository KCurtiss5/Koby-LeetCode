class Solution {
public:
    int mySqrt(int x) {
        int cur = 1;
        while (cur*cur <= x){
            cur++;
        }
        return cur-1;
    }
};

/*
This is a naive solution that doesn't pass all of the tests. Essentially this is a brute force algorithm that goes through every possible
square and the moment we find a square larger than x, we can return. With a large number, this will take a while.
*/

class Solution {
public:
    int mySqrt(int x) {
        int odd = 1;
        int counter = 0;
        for (int target = x; target >= 0; odd += 2){
            target -= odd;
            counter++;
        }
        return counter-1;
    }
};

/*
There is a pretty interesting algorithm called the Repeated Subtraction Method of Square Root. Its where you subtract consecutive odds
until the number is 0. Then the number of times you subtracted is the square root. This algorithm only works for perfect squares, but
we can make that work just fine. If it's a perfect, square we can just continue the loop, then subtract once to pseudo-"floor" it.

This does pass all tests because there is never a risk of integer overflow.
Runtime - 12ms Beats 14.32%
Memory - 8.43MB Beats 10.03%
*/