class Solution {
public:
    // s = s1 + s2;    [s1 >= s2]
    // ans should be min possible s1 - s2
    //     => min(s1 - s2)
    //     => min(s - s2 - s2)     [As s1 = s - s2]
    //     => min(s - 2*s2)
    //     means that s2 <= s/2
    
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int s = 0;
        for (auto x : stones) {
            s += x;
        }
        int sum = s / 2;
        vector<vector<bool>> dp(n + 1, vector<bool> (sum + 1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= sum; i++) {
            dp[0][i] = false;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (stones[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - stones[i - 1]] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        for (int i = sum; i >= 0; i--) {
            if (dp[n][i]) {
                return (s - (2 * i));
            }
        }
        return 0;
    }
};