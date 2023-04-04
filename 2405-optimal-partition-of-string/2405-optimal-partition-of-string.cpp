class Solution {
public:
    int partitionString(string s) {
        int cnt[26] = {0};
        int ans = 1;
        for (auto x : s) {
            if (cnt[x - 'a']) {
                ans++;
                for (int i = 0; i < 26; i++) {
                    cnt[i] = 0;
                }
            }
            cnt[x - 'a']++;
        }
        return ans;
    }
};