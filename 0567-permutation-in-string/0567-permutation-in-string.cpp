class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int a[26] = {0};
    int b[26] = {0};
    for (int i = 0; i < s1.size(); i++) {
      a[s1[i] - 'a']++;
    }
    for (int i = 0; i < s2.size(); i++) {
      b[s2[i] - 'a']++;
      if (i >= s1.size()) {
        b[s2[i - (int)s1.size()] - 'a']--;
      }
      bool ans = true;
      for (int j = 0; j < 26; j++) {
        if (a[j] != b[j]) {
          ans = false;
          break;
        }
      }
      if (ans) {
        return ans;
      }
    }
    return false;
  }
};