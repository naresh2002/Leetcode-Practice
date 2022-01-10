class Solution {
public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < 10010; i++) {
      a += '0';
      b += '0';
    }
    int n = 10000;
    string ans;
    int carry = 0;
    for (int i = 0; i < n + 5; i++) {
      int temp = (a[i] - '0' + b[i] - '0' + carry);
      if (temp > 1) {
        carry = 1;
        if (temp == 3) {
          ans += '1';
        }
        else {
          ans += '0';
        }
      }
      else {
        carry = 0;
        ans += to_string(temp);
      }
    }
    
    reverse(ans.begin(), ans.end());
    int pos = 0;
    while (ans[pos] == '0') {
      pos++;
    }
    if (pos == ans.size()) {
      return "0";
    }
    return ans.substr(pos);
  }
};