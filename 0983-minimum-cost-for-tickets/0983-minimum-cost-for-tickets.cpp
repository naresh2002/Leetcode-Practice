class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(365 + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= 365; i++) {
            if (find(days.begin(), days.end(), i) == days.end()) {  // NOT FOUND
                dp[i] = dp[i-1];
                continue;
            }
            dp[i] = min({dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
        }
        return dp[365];
    }
};