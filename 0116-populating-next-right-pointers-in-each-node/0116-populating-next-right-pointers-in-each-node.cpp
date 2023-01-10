/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    map<int, vector<Node*>> depthNodes;
    void dfs(Node *root, int depth) {
        if(!root) {
            return;
        }
        dfs(root -> right, depth + 1);
        dfs(root -> left, depth + 1);
        if (!depthNodes.count(depth)) {
            root -> next = NULL;
        }
        else {
            root -> next = depthNodes[depth].back();
        }
        depthNodes[depth].push_back(root);
    }
    Node* connect(Node* root) {
        dfs(root, 0);
        return root;
    }
};