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
    int preorderPos;
    TreeNode* solve (int l, int r, map<int, int>& m, vector<int>& preorder, vector<int>& inorder) {
        if (l > r) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preorderPos]);
        int inorderPos = m[preorder[preorderPos]];
        preorderPos++;
        root -> left = solve(l, inorderPos - 1, m, preorder, inorder);
        root -> right = solve(inorderPos + 1, r, m, preorder, inorder);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> m; // For inorder
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            m[inorder[i]] = i;
        }
        return solve(0, n - 1, m, preorder, inorder);
        // TreeNode* root = new TreeNode(preorder[0]);
    }
};