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
  vector<vector<int>> v;
  
  void preorder(TreeNode *node, int depth) {
    if (!node) {
      return;
    }
    if (v.size() == depth) {
      v.push_back({});
    }
    v[depth].push_back(node -> val);
    preorder(node -> left, depth + 1);
    preorder(node -> right, depth + 1);
  }
  vector<vector<int>> levelOrder(TreeNode* root) {
    preorder(root, 0);
    return v;
  }
};