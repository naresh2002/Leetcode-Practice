class Solution {
public:
    // int dfs (int curr, int tot, vector<int> & v, int k) {
    //     if (tot == k) {
    //         return 1;
    //     }
    //     if (curr == v.size()) {
    //         return 0;
    //     }
    //     int a = dfs(curr + 1, tot + v[curr], v, k);
    //     int b = dfs(curr + 1, tot, v, k);
    //     return a + b;
    // }
    
    int findTargetSumWays(vector<int>& v, int target) {
        int s = 0, zero = 0;
        for (auto x : v) {
            s += x;
        }
        // int s = accumulate(v.begin(), v.end(), 0);
        int n = v.size(), k = (s + target) / 2;
        if (s < target || (target + s) % 2 || k < 0) {
            return 0;
        }
        // return dfs(0, 0, v, (s + target) / 2) + zero;
        /*  S1 - S2 = target;
            S1 + S2 = sum(v);
            Adding Above Two :
            => 2(S1) = target + sum(v)
        */
        vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = k; j >= v[i]; j--) {
                dp[j] += dp[j-v[i]];
            }
        }
        return dp[k];
    }
};