/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (root->right) { bstToGst(root->right); }
        sum += root->val;
        root->val = sum;
        if (root->left) { bstToGst(root->left); }
        return root;
    }

private:
    int sum = 0;
};


/*
Understanding how binary search trees work is crucial to seeing this elegant solution. You can watch the video to understand:

Runtime - 0ms Beats 100.00%
Memory - 10.21MB Beats 12.60%
*/