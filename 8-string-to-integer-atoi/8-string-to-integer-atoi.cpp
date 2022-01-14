class Solution {
public:
  int myAtoi(string s) {
    int l = 0;
    while (s[l] == ' ') {
      l++;
    }
    int minus = 0;
    if (s[l] == '-') {
      l++;
      minus = 1;
    }
    else if (s[l] == '+') {
      l++;
    }
    long long ans = 0;
    for (int i = l; i < (int)s.size(); i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        ans *= 10LL;
        ans += (int)(s[i] - '0');
        if (ans > INT_MAX) {
          if (minus) {
            return INT_MIN;
          }
          else {
            return INT_MAX;
          }
        }
      }
      else {
        break;
      }
    }
    if (minus && ans) {
      ans *= -1;
    }
    if (ans < INT_MIN) {
      ans = INT_MIN;
    }
    if (ans > INT_MAX) {
      ans = INT_MAX;
    }
    return ans;
  }
};