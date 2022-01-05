class Solution {
public:
  int singleNumber(vector<int>& nums) {
    vector<int> v(32, 0);
    int n = nums.size();
    int temp;
    for (int i = 0; i < n; i++) {
      int k = 0;
      temp = abs(nums[i]);
      while (temp) {
        v[k++] += temp % 2;
        temp /= 2;
      }
    }
    
    long long ans = 0;
    for (int i = 0; i < 32; i++) {
      if (v[i] % 3) {
        ans += pow(2, i);
      }
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] == ans) {
        cnt++;
      }
    }
    if (cnt == 0 || cnt == 3) {
      return -ans;
    }
    return ans;
  }
};