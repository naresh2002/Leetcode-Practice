class Solution {
public:
  vector<vector<string> > ans;
  bool isPalindrome (string s, int l, int r) {
    int n = s.size();
    while (l <= r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  }
  
  void solve(int idx, string s, vector<string> &v) {
    if(idx == s.size()) {
      ans.push_back(v);
      return;
    }
    for(int i = idx; i < s.size(); i++) {
      if(isPalindrome(s, idx, i)) {
        v.push_back(s.substr(idx, i - idx + 1));
        solve(i + 1, s, v);
        v.pop_back();
      }
    }
  }
  
  vector<vector<string>> partition(string s) {
    vector<string> v;
    solve(0, s, v);
    return ans;
  }
};