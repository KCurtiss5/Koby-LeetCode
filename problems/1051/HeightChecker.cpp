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

