/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    map<TreeNode*, int> m;
    TreeNode* ans = NULL;
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) {
            return 0;
        }
        if (root == p || root == q) {
            m[root]++;
        }
        m[root] += dfs(root -> left, p, q);
        m[root] += dfs(root -> right, p, q);
        if (!ans && m[root] == 2) {
            ans = root;
            return 0;
        }
        return m[root];
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        m[root] = dfs(root, p, q);
        return ans;
    }
};