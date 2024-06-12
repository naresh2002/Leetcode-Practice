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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode *l = lowestCommonAncestor(root -> left, p, q); // If root -> left is ancestor of atleast 1, out of {p, q}
        TreeNode *r = lowestCommonAncestor(root -> right, p, q); // If root -> right is ancestor of atleast 1, out of {p, q}
        if (l && r) {
            return root; // It means that p and q are on opposite sides one on left and one on right
        }
        else {
            if (l) {
                return l;
            }
            else {
                return r;
            }
        }
    }
};