/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
  unordered_map<Node*, Node*> m;
  
  Node* dfs(Node* node) {
    if (node == NULL) {
      return node;
    }
    if (m.find(node) != m.end()) {
      return m[node];
    }
    Node *clone = new Node(node -> val);
    m[node] = clone;
    for (auto x : node -> neighbors) {
      clone -> neighbors.push_back(dfs(x));
    }
    return clone;
  }
  
  Node* cloneGraph(Node* node) {
    return dfs(node);
  }
};