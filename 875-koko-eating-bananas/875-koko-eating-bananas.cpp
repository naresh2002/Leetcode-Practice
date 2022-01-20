class Solution {
public:
  int solve(vector<int> &v, int k) {
    int ans = 0;
    for (auto x : v) {
      ans += (x + k - 1) / k;
    }
    return ans;
  }
  
  int minEatingSpeed(vector<int>& v, int h) {
    int l = 1, r = 1e9;
    while (l <= r) {
      int mid = (l + r) / 2;
      int k = solve (v, mid);
      if (k <= h) {
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }
    
    return l;
  }
};