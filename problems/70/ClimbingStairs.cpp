class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

/*
The climbing stairs problem is a good candidate for a recursive solution. Every time you climb a step, there's two paths you could have
gone to. Either, you do one of the solutions for climbStairs(n-1) and one step or one of the solutions for climbStairs(n-2) and a 
2 stair step. However, this simple algorithm fails when n gets large and the recursion becomes large.

We would have two options to fix this. One is memoization. The other is changing the algorithm to not be recursive. I opted for the 
latter.
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int oneStepBefore = 2; // Ways to climb n-1 steps
        int twoStepsBefore = 1; // Ways to climb n-2 steps

        for (int i = 3; i <= n; i++) {
            int current = oneStepBefore + twoStepsBefore;
            twoStepsBefore = oneStepBefore;
            oneStepBefore = current;
        }
        return oneStepBefore;
    }
};

/*
Runtime - 0ms Beats 100%
Memory - 7.27MB Beats 78.26%
*/