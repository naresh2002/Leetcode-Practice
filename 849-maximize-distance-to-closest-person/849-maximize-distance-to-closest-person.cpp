class Solution {
public:
  int maxDistToClosest(vector<int>& seats) {
    int n = seats.size();
    int l = 0, r = n - 1;
    while (l < n && !seats[l]) {
      l++;
    }
    while (r >= 0 && !seats[r]) {
      r--;
    }
    int ans = max(l, n - r - 1);
    for (int i = l + 1; i <= r; i++) {
      if (seats[i]) {
        ans = max(ans, (i - l) / 2);
        l = i;
      }
    }
    return ans;
  }
};