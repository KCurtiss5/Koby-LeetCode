class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m*n != original.size()) return vector<vector<int>> {};
        vector<vector<int>> vects;
        for (int i = 0; i < m; i++){
            vects.push_back(vector<int>());
        }
        for (int i = 0; i < original.size(); i++){
            vects[i/n].push_back(original[i]);
        }
        return vects;
    }
};

/*
This is a simple implementation. If its not possible to create the array using all elements, we return an empty array. Otherwise,
we append every vector we'd need. And element by element, we add it to its correct spot.
But its slow compared to other implementations. Why is that? Let's see if we can make a few improvements.
Runtime - 98ms Beats 8.92%
Memory - 95.26MB Beats 13.33%
*/