class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for (auto x : bank) {
            int cnt = 0;
            for (auto y : x) {
                if (y == '1') {
                    cnt++;
                }
            }
            if (cnt) {
                v.push_back(cnt);
            }
        }
        int n = v.size();
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += (v[i] * v[i - 1]);
        }
        return ans;
    }
};