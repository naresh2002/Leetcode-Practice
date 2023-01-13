class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0};
        int tot = 0;
        int m = 0;
        for (auto x : tasks) {
            if (!cnt[x - 'A']) {
                tot++;
            }
            cnt[x - 'A']++;
            m = max(m, cnt[x - 'A']);
        }
        int maxCount = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] == m) {
                maxCount++;
            }
        }
        int ans = max((int)tasks.size(), m + (n * (m - 1)) + maxCount - 1);
        return ans;
    }
};