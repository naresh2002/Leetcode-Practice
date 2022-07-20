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
    vector<double> ans;
    vector<int> cnt;
    
    void solve (TreeNode *root, int level) {
        if (!root) {
            return;
        }
        if (ans.size() == level) {
            ans.push_back(0);
            cnt.push_back(0);
        }
        ans[level] += root -> val;
        cnt[level]++;
        solve(root -> left, level + 1);
        solve(root -> right, level + 1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        solve(root, 0);
        for (int i = 0; i < ans.size(); i++) {
            ans[i] /= cnt[i];
        }
        return ans;
    }
};