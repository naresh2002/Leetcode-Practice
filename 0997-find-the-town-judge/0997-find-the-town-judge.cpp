class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n + 1, 0);
        for (auto x : trust) {
            v[x[0]]--;
            v[x[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (v[i] == n - 1) {
                return i;
            }
        }
        return -1;
    }
};