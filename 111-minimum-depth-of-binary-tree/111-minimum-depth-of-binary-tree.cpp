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
    int solve (TreeNode *root, int depth) {
        if (!root -> left && !root -> right) {
            return depth;
        }
        int ans = 1e9;
        if (root -> left) {
        ans = min(ans, solve (root -> left, depth + 1));
        }
        if (root -> right) {
        ans = min(ans, solve (root -> right, depth + 1));
        }
        return ans;
    }
    
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int ans = solve(root, 1);
        return ans;
    }
};