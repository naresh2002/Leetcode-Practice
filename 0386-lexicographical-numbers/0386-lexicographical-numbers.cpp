class Solution {
public:
    struct TrieNode {
        vector<TrieNode*> child;
        
        TrieNode() {
            child.resize(10, NULL);
        }
    };
    
    void insert (TrieNode* node, int num) {
        string s = to_string(num);
        for (auto x : s) {
            int n = x - '0';
            if (node -> child[n] == NULL) {
                node -> child[n] = new TrieNode();
            }
            node = node -> child[n];
        }
    }
    
    vector<int> ans;
    void solve (TrieNode* node, int n) {
        if (!node) {
            return;
        }
        n *= 10;
        for (int i = 0; i < 10; i++) {
            if (node -> child[i]) {
                ans.push_back(n + i);
                solve(node -> child[i], (n + i));
            }
        }
    }
    
    vector<int> lexicalOrder(int n) {
        TrieNode* node = new TrieNode();
        for (int i = 1; i <= n; i++) {
            insert(node, i);
        }
        solve(node, 0);
        return ans;
    }
};