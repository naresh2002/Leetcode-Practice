class Solution {
public:
  int trailingZeroes(int n) {
    int c = 0;
    int k = 5;
    while (k <= n) {
      c += (n / k);
      k *= 5;
    }
    return c;
  }
};