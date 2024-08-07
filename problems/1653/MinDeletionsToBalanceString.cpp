class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int countB = 0;
        for (auto c : s) {
            if (c == 'b') {
                countB++;
            } else {
                ans = min(ans + 1, countB);
            }
        }
        return ans;
    }
};

/*
Runtime - 69ms Beats 96.49% O(N)
Memory - 23.58MB Beats 76.55%
*/