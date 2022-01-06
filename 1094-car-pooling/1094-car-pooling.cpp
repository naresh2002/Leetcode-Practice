class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int p[1005];
    memset(p, 0, sizeof p);
    for (auto x : trips) {
      p[x[1]] += x[0];
      p[x[2]] -= x[0];
    }
    if (p[0] > capacity) return false;
    for (int i = 1; i < 1005; i++) {
      p[i] += p[i - 1];
      if (p[i] > capacity) {
        return false;
      }
    }
    return true;
  }
};