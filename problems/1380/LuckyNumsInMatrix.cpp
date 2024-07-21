class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> lucky;

        for (vector<int> each: matrix) {
            vector<int>::iterator row_min = min_element(each.begin(), each.end());
            int index = distance(each.begin(), row_min);
            int maximum = matrix[0][index];

            for (int i = 1; i < matrix.size(); i++){
                maximum = max(maximum, matrix[i][index]);
            }
            if (maximum == *row_min){
                lucky.push_back(*row_min);
            }
        }
        return lucky;
    }
};

/*
This is a bit of a basic solution. For every row, there is one minimum element which is capable of being the lucky number.
Then we iterate through every element in that index, keeping track of the maximum. If the element in the minimum in its row and the max
in its column, then we append to lucky and return it. This is a naive solution.

Runtime - 16ms Beats 56.54% O(M*N)
Memory - 14.97MB Beats 5.02%

There are probably more elegant solutions.
*/