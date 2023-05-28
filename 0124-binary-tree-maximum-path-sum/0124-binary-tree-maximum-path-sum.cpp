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
    // HELP FROM : https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/2899997/C%2B%2B-oror-DFS-oror-Subtree-Sum-Method
    int solve(TreeNode *root, int &ans) {
        if (!root) {
            return 0;
        }
        int l = max(solve(root -> left, ans), 0);
        int r = max(solve(root -> right, ans), 0);
        int k = root -> val;
        ans = max(ans, l + r + k);
        return (k + max(l, r));
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = -1e6;
        solve(root, ans);
        return ans;
    }
};