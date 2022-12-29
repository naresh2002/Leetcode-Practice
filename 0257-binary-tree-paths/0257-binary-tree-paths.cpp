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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, vector<int> &v) {
        if (!root) {
            return;
        }
        v.push_back(root -> val);
        if (!root -> left && !root -> right) {
            ans.push_back(v);
        }
        dfs(root -> left, v);
        dfs(root -> right, v);
        v.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> temp;
        dfs(root, temp);
        vector<string> v;
        for (auto x : ans) {
            string s;
            for(auto y : x) {
                s += to_string(y);
                s += "->";
            }
            int n = s.size() - 2;
            v.push_back(s.substr(0, n));
        }
        return v;
    }
};