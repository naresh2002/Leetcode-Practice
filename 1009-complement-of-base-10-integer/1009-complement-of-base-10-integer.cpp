class Solution {
public:
  int bitwiseComplement(int n) {
    if (n == 0) {
      return 1;
    }
    long long k = 1;
    int cnt = 0;
    while (k <= n) {
      k *= 2;
      cnt++;
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
      if (!((1 << i) & n)) {
        ans += (1 << i);
      }
    }
    return ans;
  }
};