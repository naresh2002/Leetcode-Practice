class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0;
        for (auto x : bank) {
            int cnt = 0;
            for (auto y : x) {
                if (y == '1') {
                    cnt++;
                }
            }
            if (cnt) {
                ans += (prev * cnt);
                prev = cnt;
            }
        }
        return ans;
    }
};