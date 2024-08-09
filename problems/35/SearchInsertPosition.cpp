class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //binary search
        int start = 0;
        int end = nums.size();
        int index = nums.size()/2;

        while (end-start > 1){
            if (nums[index] == target) return index;
            if (nums[index] > target) end = index;
            else start = index;
            index = (end + start) / 2;
        }

        if (target > nums[index]) return index+1;
        return index;
    }
};

/*
This is a classic binary search problem. So we do our binary search, if we find the target, then we return the index.
If not, we see where we need to place it, either one after we're at now, or we replace the position.
Runtime - 0ms Beats 100.00% O(Log(n))
Memory - 12.46MB Beats 30.01%
*/

/*
But we can improve this! I completely forgot that you can also exclude the current index, so end = index and start = index.
Replace with end = index-1; start = index+1;
*/


