/*
You are given two positive integers n and k.

You can choose any bit in the binary representation of n that is equal to 1 and change it to 0.

Return the number of changes needed to make n equal to k. If it is impossible, return -1.


Example 1:

Input: n = 13, k = 4

Output: 2

Explanation:
Initially, the binary representations of n and k are n = (1101)2 and k = (0100)2.
We can change the first and fourth bits of n. The resulting integer is n = (0100)2 = k.

*/

class Solution {
public:
    int minChanges(int n, int k) {
        //assuming its possible, we can essentially find the number of changes we need to make
        //by xoring n & k then counting the number of bits.
        //But we can only go from 1 to 0 in n.. meaning if there's any 1s in k that is a 0
        //in n, its not possible.
        //So we can use n as a bit mask. If k AND n isn't k, then we know there's a 1 in k not in n, and therefore its impossible.
        //Then we can XOR n and k, then count the number of ones using Brian Kernighans algorithm.
        if ((k&n) != k){
            return -1;
        }
        //Brian Kernighans alg
        n ^= k;
        int counter = 0;
        while (n) {
            n &= (n - 1);
            counter++;
        }
        return counter;
    }
};