class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);  // 1-based INDEXING
        dp[0] = true;
        for (int j = 0; j < n; j++) {   // ENDING point
            for (int i = 0; i <= j; i++) {   // STARTING point
                if (dp[i] && find(wordDict.begin(), wordDict.end(), s.substr(i, j - i + 1)) != wordDict.end()) {
                    dp[j + 1] = true;
                }
            }
        }
        return dp[n];
    }
};