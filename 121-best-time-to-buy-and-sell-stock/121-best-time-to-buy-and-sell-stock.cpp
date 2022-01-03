class Solution {
public:
  
  int maxProfit(vector<int>& prices) {
    int minPrice = 1e5;
    int maxProfit = 0;  
    for (auto x : prices) {
      minPrice = min(minPrice, x);
      maxProfit = max(maxProfit, x - minPrice);
    }
    return maxProfit;
  }
};