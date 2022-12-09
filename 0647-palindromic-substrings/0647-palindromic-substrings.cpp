class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++) {          // END
            for (int j = 1; j <= n; j++) {      // START
                if (i == j) {
                    dp[i][j] = 1;
                    ans++;
                }
                else if (j < i && s[j - 1] == s[i - 1]) {
                    if (dp[j + 1][i - 1] == i - j - 1) {
                        dp[j][i] = dp[j + 1][i - 1] + 2;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};