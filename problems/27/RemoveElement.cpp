class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = nums.size()-1; i >= 0; i--){
            if (nums[i] == val){
                nums.erase(nums.begin()+i);
            }
        }
        return nums.size();
    }
};

/*
This is a very simple problem. We can iterate through the list using the erase method. We iterate backwards because it is slightly
faster. The erase method linearly pushes every element after the element we delete to one spot earlier in the list. So therefore,
if we can delete the quickest elements first, we can save some operations.

Runtime - 0ms Beats 100.00% O(N)
Memory - 10.76MB Beats 6.64%

It can be done a bit faster with a different algorithm. First I thought about swapping elements so we can avoid moving every element
multiple times. However, I dont even need to swap since we're removing the element anyways, so we can flat out replace it.

*/