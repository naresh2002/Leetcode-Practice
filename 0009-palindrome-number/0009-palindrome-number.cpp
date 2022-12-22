class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long a = x, y = 0;
        while (a) {
            y *= 10;
            y += (a % 10);
            a /= 10;
        }
        return x == y;
    }
};