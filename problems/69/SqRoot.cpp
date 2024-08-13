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

Lets take a more advanced math approach to this, however.
*/

class Solution {
public:
    int mySqrt(int x) {
        double n = 1;
        for (int i = 0; i < 20; i++) { //20 passed all test cases
            n = n-(((pow(n,2))-x)/(2*n)); //newtons algorithm
        }
        return floor(n);
    }
};

/*
This is newtons approximation algorithm. With every iteration, we can get closer to the real answer.
Runtime - 3ms Beats 40.18% O(1)
Memory - 8.40MB Beats 10.39%
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;

        int start = 1;
        int end = x/2;
        int res = 0;

        while (start <= end) {
            int mid = start + ((end-start)/2);
            if (mid<=x/mid){
                start = mid+1;
                res=mid;
            }
            else {
                end=mid-1;
            }
        }

        return res;
    }
};