class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int best = nums[0];
    int curr_max = nums[0];
    int curr_min = nums[0];
    int n = nums.size();
    
    for (int i = 1; i < n; i++) {
      int temp = max({nums[i], curr_max * nums[i], curr_min * nums[i]});
      curr_min = min({nums[i], curr_max * nums[i], curr_min * nums[i]});
      curr_max = temp;
      
      best = max(best, curr_max);
    }
    return best;
  }
};