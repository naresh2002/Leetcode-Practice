class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        map<int, vector<vector<int>>> m;
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            m[(x * x) + (y * y)].push_back({x, y});
        }
        vector<vector<int>> ans;
        for (auto x : m) {
            for (auto y : m[x.first]) {
                if (k == 0) {
                    break;
                }
                ans.push_back(y);
                k--;
            }
        }
        return ans;
    }
};