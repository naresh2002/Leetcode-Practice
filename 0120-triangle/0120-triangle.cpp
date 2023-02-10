class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        dp.push_back(triangle[0]);
        for (int i = 1; i < n; i++) {
            vector<int> v;
            int sz = triangle[i].size();
            v.push_back(dp[i - 1][0] + triangle[i][0]);
            for (int j = 1; j < sz - 1; j++) {
                v.push_back(min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]);
            }
            v.push_back(dp[i - 1][i - 1] + triangle[i][i]);
            dp.push_back(v);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};