class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 1e9;
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