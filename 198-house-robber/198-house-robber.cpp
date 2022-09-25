class Solution {
public:
    int rob(vector<int>& v) {
        if (v.size() == 1) {
            return v[0];
        }
        int dp[105] = {0};        
        dp[0] = v[0];
        dp[1] = max(v[0],v[1]);
        for (int i = 2; i < v.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
        }
        return dp[v.size() - 1];
    }
};