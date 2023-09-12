class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        map<int,vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> v;
        for (auto x : m) {
            int cnt = 0;
            for (auto y : x.second) {
                v.push_back(y);
                cnt++;
                if (cnt == x.first) {
                    cnt = 0;
                    ans.push_back(v);
                    v.clear();
                }
            }
        }
        return ans;
    }
};