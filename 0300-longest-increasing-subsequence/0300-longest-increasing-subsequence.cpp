class Solution {
public:
    int longestCommonSubsequence(vector<int> v1, vector<int> v2) {
        int n = v1.size();
        int m = v2.size();
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (!i || !j) {
                    dp[i][j] = 0;
                }
                else {
                    if (v1[i - 1] == v2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else {
                        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                    }
                }
            }
        }
        return dp[n][m];
    }
    
    int lengthOfLIS(vector<int>& v2) {
        unordered_map<int, int> m;
        for (auto x : v2) {
            m[x] = 1;
        }
        vector<int> v1;
        for (auto x : m) {
            v1.push_back(x.first);
        }
        sort(v1.begin(), v1.end());
        return longestCommonSubsequence(v1, v2);
    }
};