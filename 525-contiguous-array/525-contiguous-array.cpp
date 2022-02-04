class Solution {
public:
  int findMaxLength(vector<int>& v) {
    int n = v.size();
    int a[n + 1];
    a[0] = 0;
    unordered_map<int,int> m;
    m[0] = 0;
    for (int i = 0; i < n; i++) {
      a[i + 1] = a[i] + v[i];
      if (v[i] == 0) {
        a[i + 1]--;
      }
      if (!m.count(a[i + 1])) {
        m[a[i + 1]] = i + 1;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, i - m[a[i + 1]] + 1);
    }
    return ans;
  }
};