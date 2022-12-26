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
    map<TreeNode*, int> m;
    int solve(TreeNode* root, TreeNode* parent) {
        if (!root) {
            return 0;
        }
        int a = solve(root -> left, root);
        int b = solve(root -> right, root);
        m[root] = a + b;
        if (root -> val == parent -> val) {
            return max(a, b) + 1;
        }
        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int a = solve(root -> left, root);
        int b = solve(root -> right, root);
        m[root] = a + b;
        int ans = 0;
        for (auto x : m) {
            // cout << x.first -> val << " " << x.second << endl;
            ans = max(ans, x.second);
        }
        return ans;
    }
};