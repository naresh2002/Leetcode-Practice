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
  int ans = 0;
  void dfs (TreeNode *root, int k) {
    k = (k * 2) + root -> val;
    if (!root -> left && !root -> right) {
      ans += k;
      return;
    }
    if (root -> left) {
      dfs(root -> left, k);
    }
    if (root -> right) {
      dfs(root -> right, k);
    }
  }
  
  int sumRootToLeaf(TreeNode* root) {
    dfs(root, 0);
    return ans;
  }
};