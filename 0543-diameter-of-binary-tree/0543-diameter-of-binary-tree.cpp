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
    int ans;
    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        ans = max(ans, l + r);  // Not l + r + 1 as it is length not no. of nodes
        return max(l, r) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};