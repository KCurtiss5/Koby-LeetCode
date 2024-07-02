class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersection;
        for (auto num: nums1){
            auto p = find(nums2.begin(), nums2.end(), num);
            if (p != nums2.end()){
                // we have the element
                intersection.push_back(num);
                nums2.erase(p);
            }
        }
        return intersection;
    }
};

/*
This code compares every element from nums1 to nums2 and if it finds the element, it appends it to intersection.
Then it deletes the element. Since std::find is a linear search, it makes no improvements to iterate over the smaller list.
O(N*M)
Runtime - 0ms Beats 100%
Memory - 12.41MB Beats 91.17%
*/