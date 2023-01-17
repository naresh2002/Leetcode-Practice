class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int zero[n + 2], one[n + 1];    // Prefix of ones AND Suffix of zeros
        one[0] = 0;
        for (int i = 0; i < n; i++) {
            one[i + 1] = one[i];
            if (s[i] == '1') {
                one[i + 1]++;
            }
        }
        zero[n + 1] = 0;
        for (int i = n - 1; i >= 0; i--) {
            zero[i + 1] = zero[i + 2];
            if (s[i] == '0') {
                zero[i + 1]++;
            }
        }
        
        int ans = n;
        for (int i = 0; i <= n; i++) {
            ans = min(ans, one[i] + zero[i + 1]);
        }
        return ans;
    }
};