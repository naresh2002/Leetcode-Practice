class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    set<int> s;
    for (auto x : nums) {
      s.insert(x);
    }
    vector<int> a;
    for (auto x : s) {
      a.push_back(x);
    }
    sort(a.begin(), a.end());
    int n = a.size();
    int ans = 1;
    int i = 1;
    while (i < n) {
      int cnt = 1;
      while (i < n && a[i] - a[i - 1] == 1) {
        cnt++;
        i++;
      }
      ans = max(ans, cnt);
      i++;
    }
    return ans;
  }
};