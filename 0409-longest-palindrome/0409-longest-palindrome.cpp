class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        int cnt[256] = {0};
        for (auto x : s) {
            cnt[x]++;
        }
        int oddCnt = 0;
        for (int i = 0; i < 256; i++) {
            if (cnt[i] % 2) {
                oddCnt++;
            }
        }
        if (oddCnt) {
            return n - oddCnt + 1;
        }
        return n;
    }
};