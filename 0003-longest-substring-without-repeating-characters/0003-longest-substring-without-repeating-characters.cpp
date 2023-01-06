class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int cnt[256] = {0};
        int ans = 0;
        for (int i = 0, j = 0; j < n; j++) {
            cnt[s[j]]++;
            while (cnt[s[j]] > 1) {
                cnt[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};