class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (!i || !j) {
                    dp[i][j] = max(i, j);
                    continue;
                }
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int insertChar = dp[i][j - 1] + 1;
                    int deleteChar = dp[i - 1][j] + 1;
                    int replaceChar = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min({insertChar, deleteChar, replaceChar});
                }
            }
        }
        return dp[n][m];
    }
};