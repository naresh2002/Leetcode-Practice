class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> dp (n, 0);
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; ) {
                if (temperatures[j] > temperatures[i]) {
                    dp[i] = j - i;
                    break;
                }
                if (dp[j]) {
                    j += dp[j];
                }
                else {
                    break;
                }
            }
        }
        return dp;
    }
};