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
    unordered_map<TreeNode*, int> m;
    int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (m.count(root)) {
            return m[root];
        }
        
        int ansIncludingRoot = root -> val;
        if (root -> left) {
            ansIncludingRoot += rob(root -> left -> left);
            ansIncludingRoot += rob(root -> left -> right);
        }
        if (root -> right) {
            ansIncludingRoot += rob(root -> right -> left);
            ansIncludingRoot += rob(root -> right -> right);
        }
        
        int ansExcludingRoot = 0;
        ansExcludingRoot += rob(root -> left);
        ansExcludingRoot += rob(root -> right);
        
        int ans = max(ansIncludingRoot, ansExcludingRoot);
        m[root] = ans;
        return ans;
    }
};