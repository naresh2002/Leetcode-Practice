class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        bool wordEnd;
        
        TrieNode() {
            wordEnd = false;
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
            }
            currNode = currNode -> child[ch - 'a'];
        }
        currNode -> wordEnd = true;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* node = new TrieNode();
        for (auto x : wordDict) {
            insertTrie(node, x);
        }
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= n; i++) {
            if (dp[i] == 0) {
                continue;
            }
            TrieNode* p = node;
            int j = i;
            while (j < n && p -> child[s[j] - 'a']) {
                p = p -> child[s[j] - 'a'];
                j++;
                if (p -> wordEnd) {
                    dp[j] = 1;  // 1 based indexing
                }
            }
            if (dp[n]) {
                return true;
            }
        }
        return false;
    }
};
