class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool wordEnd;
        int childCount;
        
        TrieNode() {
            wordEnd = false;
            childCount = 0;
            for (int i = 0; i < 26; i++) {
                child[i] = NULL;
            }
        }
    };
    
    void insertTrie(TrieNode* node, string s) {
        TrieNode* currNode = node;
        for (auto ch : s) {
            if (currNode -> child[ch - 'a'] == NULL) {
                currNode -> child[ch - 'a'] = new TrieNode();
                currNode -> childCount++;
            }
            currNode = currNode -> child[ch - 'a'];
        }
        currNode -> wordEnd = true;
    }
    
    string dfs(TrieNode *node) {
        if (!node || node -> wordEnd || node -> childCount > 1) {
            return "";
        }
        string ans = "";
        for (int i = 0; i < 26; i++) {
            if (node -> child[i]) {
                ans += (char(i + 'a') + dfs(node -> child[i]));
                break;
            }
        }
        return ans;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* node = new TrieNode();
        for (auto s : strs) {
            insertTrie(node, s);
        }
        // string ans = "";
        return dfs(node);
    }
};