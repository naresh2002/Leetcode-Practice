class Solution {
public:  
  int removeCoveredIntervals(vector<vector<int>>& v) {
    sort (v.begin(), v.end(), [&](vector<int> &a, vector<int> &b) {
      if (a[0] != b[0]) {
        return a[0] < b[0];
      }
      return a[1] > b[1];
    });
    
    int ans = v.size(), end = INT_MIN;
    for(int i = 0; i < v.size(); i++) {
      if(v[i][1] <= end) {
        ans--;
      }
      else {
        end = v[i][1];
      }
    }
    return ans;
  }
};