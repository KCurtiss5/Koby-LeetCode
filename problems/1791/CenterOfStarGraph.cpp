class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // the node is the only node with more than two edges
        // greedy algorithm to find the first node with more than two edges
        set<int> seen;
        for (auto vect: edges){
            for (auto node: vect){
                auto ret = seen.insert(node);
                if (ret.second == false){
                    return node;
                }
            }
        }
        return 0;
    }
};

/*
One principal of a star graph to understand is the fact that only one node will ever have multiple edges. So we can create a set,
then insert into the set. The line (ret.second) checks whether the element has already been inserted.

Runtime - 146ms Beats 41.99%
Memory - 70.71MB Beats 77.19%
*/