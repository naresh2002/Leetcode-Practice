class Solution {
public:
  int addDigits(int n) {
    while (n >= 10) {
      int k = 0;
      while (n) {
        k += n % 10;
        n /= 10;
      }
      n = k;
    }
    return n;
  }
};