class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int wrong = 0;
        vector<int> expected = heights; //deep copy
        sort(expected.begin(), expected.end());
        for (size_t i = 0; i < heights.size(); i++) {
            if (heights[i] != expected[i]){
                wrong++;
            }
        }
        return wrong;
    }
};

/*
After reading the problem, the naive solution becomes apparent. The entire point of the problem is to see what the difference
between the current lineup of student heights versus the expected. So you can simply sort the current heights and compare!
Runtime - 0ms Beats 100.00% of users with C++
Memory - 10.15MB Beats 44.04% of users with C++

This is very fast despite a O(n log(n)) quicksort, which is surprising. However, in a real application using students,
real class sizes would not be a challenge for this algorithm. However, in a hypothetical where we have a class size of 
ten thousand who are ordered exactly in the worst case for quick sort. Would be O(n^2) with ten thousand students taking a while.
So lets get this down to O(n).
*/

/*
For this attempt, I can essentially count the frequency of each integer. Then we can progress through the map to compare the
expected versus the actual.
*/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int max = 0;
        int wrong = 0;
        map<int, int> freq;
        for (auto num : heights){
            freq[num]++; //[] implicit insert with postincrement
            max = (max + num + abs(max-num))/2; //branchless max
        }
        int i, j = 0;
        while (i <= max){
            if (freq[i] == 0){
                i++;
                continue;
            }
            if(heights[j] != i){
                wrong++;
            }
            j++;
            freq[i]--;
        }
        return wrong;
    }
};

/*
This uses a frequency map. It determines what heights[j] should be in a sorted order, and if its not that, then increments wrong.
Funny enough its slower.
Runtime - 5ms Beats 31.17% of users with C++
Memory - 10.82MB Beats 10.73% of users with C++
*/
