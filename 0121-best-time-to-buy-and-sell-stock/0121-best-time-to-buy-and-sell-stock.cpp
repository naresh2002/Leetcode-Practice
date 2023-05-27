class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        for (auto x : prices) {
            if (x < buy) {
                buy = x;
            }
            profit = max(profit, x - buy);
        }
        return profit;
    }
};