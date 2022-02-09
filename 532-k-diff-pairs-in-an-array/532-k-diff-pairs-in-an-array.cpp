class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (auto x : nums) {
      m[x]++;
    }
    int ans = 0;
    for (auto x : m) {
      if (m.count(x.first - k)) {
        if (k == 0 && m[x.first] < 2) {
          continue;
        }
        // cout << x.first << endl;
        ans++;
      }
    }
    return ans;
  }
};