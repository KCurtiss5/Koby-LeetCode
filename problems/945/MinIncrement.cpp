class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int moves = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++){
            if (nums[i] >= nums[i+1]){
                moves += nums[i] - nums[i+1] + 1;
                nums[i+1] = nums[i]+1;
            }
        }
        return moves;
    }
};

/*
So essentially, this code sorts the list, then it ensures that there are no duplicate numbers by always increasing duplicates.
So for example: 3,2,1,2,1,7
It gets sorted to 1,1,2,2,3,7
Steps:
1. 1,2,2,2,3,7 moves = 1
2. 1,2,3,2,3,7 moves = 2
3. 1,2,3,4,3,7 moves = 4
4. 1,2,3,4,5,7 moves = 6

Runtime - 111ms Beats 80.36%
Memory - 69.08MB Beats 80.37%
*/