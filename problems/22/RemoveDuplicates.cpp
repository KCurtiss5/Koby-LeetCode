// First Attempt

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == nums[i-1]){
                nums.erase(nums.begin()+i);
                --i;
            }
        }
        return nums.size();
    }
};

/*
This uses a simple algorithm that just loops through the vector and when it detects a duplicate, uses the standard vector operation
erase to remove it. Then ofc, we have to decrement i. Then we just return the size. This works, but is there a better solution?
Its pretty slow:
Runtime - 55ms Beats 5.30% of users with C++
Memory - 21.00MB Beats 91.17% of users with C++
We have to remove the duplicates IN-PLACE. So no tricks like creating a set with the vector and returning the size of the set.

Why is this slow? Because nums.erase() does a lot! First it has to identify, then delete the integer. Then it shifts over all 
elements one to the left (this is the troublemaker). The cppreference page literally states this process is inefficient.
Then it updates vector.size() and returns an iterator. If we can do this without .erase, it will be much faster.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[j] = nums[i];
                j++;
            }
        }
        nums.resize(j);
        return j;
    }
};


/*
This algorithm uses what is essentially two pointers to copy elements in order. Then once we are done, we can resize the
vector to j (which is how many unique elements there are). Since this avoids vector.erase(), it is much faster.
Runtime - 5ms Beats 78.41% of users with C++
Memory - 21.18MB Beats 29.61% of users with C++
*/