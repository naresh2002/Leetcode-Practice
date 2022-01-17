class Solution {
public:
  bool wordPattern(string pattern, string s) {
    vector<string> v;
    string temp;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == ' ') {
        v.push_back(temp);
        temp = "";
        continue;
      }
      temp += s[i];
    }
    if ((int)temp.size()) {
      v.push_back(temp);
    }
    int n = v.size();
    
    if ((int)pattern.size() != n) {
      return false;
    }
    
    map<char, string> m;
    for (int i = 0; i < n; i++) {
      if (!m.count(pattern[i])) {
        m[pattern[i]] = v[i];
      }
      else {
        if (m[pattern[i]] != v[i]) {
          return false;
        }
      }
    }
    
    map<string, char> m2;
    for (int i = 0; i < n; i++) {
      if (!m2.count(v[i])) {
        m2[v[i]] = pattern[i];
      }
      else {
        if (m2[v[i]] != pattern[i]) {
          return false;
        }
      }
    }
    return true;
  }
};