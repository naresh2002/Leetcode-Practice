class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (!i || !j) {
                    dp[i][j] = max(i, j);
                }
                else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int insertChar = dp[i - 1][j] + 1;
                    int deleteChar = dp[i][j - 1] + 1;
                    int replaceChar = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min({insertChar, deleteChar, replaceChar});
                }
            }
        }
        return dp[m][n];
    }
};