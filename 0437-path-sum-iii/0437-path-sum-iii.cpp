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
    map<TreeNode*, vector<long long>> m;
    void solve(TreeNode *root, TreeNode *parent) {
        if (!root) {
            return;
        }
        m[root].push_back(root -> val);
        for (auto x : m[parent]) {
            //  Using INT_MIN and INT_MAX can fail for extreme cases
            //  like first add INT_MAX + 5 and then subtract 6 from it
            //  but in our case it will nott reach till end condition
            if ((x + root -> val) < INT_MIN || (x + root -> val) > INT_MAX) {
                continue;
            }
            m[root].push_back(x + root -> val);
        }
        solve(root -> left, root);
        solve(root -> right, root);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }
        m[root].push_back(root -> val);
        solve(root -> left, root);
        solve(root -> right, root);
        map<int, int> cnt;
        for (auto x : m) {
            for (auto y : m[x.first]) {
                cnt[y]++;
            }
        }
        for (auto x : cnt) {
            cout << x.first << " " << x.second << endl;
        }
        return cnt[targetSum];
    }
};