class Solution {
public:
  bool detectCapitalUse(string word) {
    int cnt = 0;
    int n = word.size();
    for (int i = 0; i < n; i++) {
      if (word[i] >= 'A' && word[i] <= 'Z') {
        cnt++;
      }
    }
    if (cnt == n || cnt == 0 || (cnt == 1 && word[0] <= 'Z')) {
      return true;
    }
    return false;
  }
};