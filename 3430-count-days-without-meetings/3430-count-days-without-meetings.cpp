class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        sort(meetings.begin(), meetings.end());
        vector<vector<int>> v;
        v.push_back(meetings[0]);
        for (int i = 1; i < n; i++) {
            if (meetings[i][0] <= v.back()[1] + 1) {
                v.back()[1] = max(v.back()[1], meetings[i][1]);
            }
            else {
                v.push_back(meetings[i]);
            }
        }
        int ans = days;
        for (auto x : v) {
            ans -= (x[1] - x[0] + 1);
        }
        return ans;
    }
}; 