bool comp(vector<int> &a, vector<int> &b){
  return a[1] < b[1];
}

class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& v) {
    int n = v.size();
    sort(v.begin(), v.end(), comp);
    int ans = 0, p;
    for (int i = 0; i < n; i++) {
      if (ans == 0 || p < v[i][0]) {
        ans++;
        p = v[i][1];
      }
    }
    return ans;
  }
};