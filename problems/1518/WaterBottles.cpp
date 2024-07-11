class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = 0;
        int empty = 0;
        while (numBottles != 0) {
            drank += numBottles;
            empty += numBottles;
            numBottles = 0;
            numBottles = empty/numExchange;
            empty %= numExchange;
        }
        return drank;
    }
};

/*
This is a very simple solution as if you were doing this yourself.
First, you drink all of the full bottles (stored in numBottles). Add that to drank. Then make sure you add them to the empty bottles.
Then you go ahead and exchange all of the empty bottles that you can and go again!
While simple, this solution worked pretty well.

Runtime - 0ms Beats 100.00%
Memory - 7.44MB Beats 36.73%
*/