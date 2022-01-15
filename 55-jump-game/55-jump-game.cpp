class Solution {
public:
  bool canJump(vector<int>& v) {
    int k = v[0];
    int n = v.size();
    int pos = n;
    for (int i = 0; i < n; i++) {
      k--;
      if (v[i] > k) {
        k = v[i];
      }
      if (k == 0) {
        pos = i + 1;
        break;
      }
    }
    if (pos == n) {
      return true;
    }
    return false;
  }
};