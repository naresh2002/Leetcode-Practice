class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool numStarted = false;
        bool negative = false;
        for (auto ch : s) {
            if (!numStarted) {
                if (ch == ' ') {
                    continue;
                }
                else if (ch == '+') {
                    numStarted = true;
                    continue;
                }
                else if (ch == '-') {
                    negative = true;
                    numStarted = true;
                }
                else if (ch >= '0' && ch <= '9') {
                    ans *= 10LL;
                    ans += (ch - '0');
                    numStarted = true;
                }
                else {
                    break;
                }
            }
            else {
                if (ch >= '0' && ch <= '9') {
                    ans *= 10LL;
                    ans += (ch - '0');
                }
                else {
                    break;
                }
            }
            if (ans >= 10LL * INT_MAX) {
                ans = 100LL + INT_MAX; // As INT range is -2^31 to 2^31 - 1. Positive have 1 less number than negative so we will get wrong ans when converting ans to negative when ans > INT_MAX
            }
        }
        if (negative) {
            ans *= -1LL;
        }
        if (ans > INT_MAX) {
            ans = INT_MAX;
        }
        if (ans < INT_MIN) {
            ans = INT_MIN;
        }
        return ans;
    }
};