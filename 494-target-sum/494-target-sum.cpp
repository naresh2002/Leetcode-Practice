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
        int s = 0;
        for (auto x : v) {
            s += x;
        }
        int n = v.size(), new_target = (s + target) / 2;
        if (s < target || (target + s) % 2 || new_target < 0) {
            return 0;
        }
        // return dfs(0, 0, v, (s + target) / 2);
        /*  S1 - S2 = target;
            S1 + S2 = sum(v);
            Adding Above Two :
            => 2(S1) = target + sum(v)
        */
        vector<int> dp(new_target + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = new_target; j >= v[i]; j--)
                dp[j] += dp[j-v[i]];
        return dp[new_target];
    }
};