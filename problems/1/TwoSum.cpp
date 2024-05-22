#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen_numbers = {{nums[0], 0}};
        for (int i = 1; i < nums.size(); i++){
            int num = nums[i];
            if (seen_numbers.contains(target-num)){
                return {seen_numbers[target-num], i};
            }
            seen_numbers.insert({num, i});
        }
        return {};
    }
};

/* 
Utilizes a hashtable (or unordered_map) to complete this in one pass. 
It uses a hashtable with the number as the key, and the index as the value in the key,value pair.
This is only possible because each solution is unique. This code would break given an input like [3,3,3,3], target=6
but since this does not give unique answers, it is not valid input. Input like [3,3], target=6 still works despite using a hashtable
because when it finds a solution, it does not insert it into the table and if there were any duplicate numbers without a solution,
it is no longer a valid input. So because we can get O(1) lookups with a hashtable without any problems, thats what I used.
The algorithm takes one pass through the list. It first inserts element 0 into the map. Then it goes element by element
checking whether the theoretical cooresponding element (target-num so that target-num+num=target) exists in the map. If its
in the map, it is in the list and we can get the index for it, and use the current index in the loop (i). We also include return {}
so that C++ doesn't issue a compiler warning despite this code always finding an answer with valid input.
*/

//Runtime: 6ms, Memory: 16MB
//Beats: Beats 89.03%, 30.05%
