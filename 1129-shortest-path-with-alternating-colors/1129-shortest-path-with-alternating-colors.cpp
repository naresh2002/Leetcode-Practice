class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges){
        vector<int> ans(n, -1), v1(n, 0), v2(n, 0);
        vector<vector<pair<int, int>>> vp(n);
        queue<pair<int, int>> q;

        for (auto x : red_edges) {
            vp[x[0]].push_back({x[1], 1});
        }
        for (auto x : blue_edges) {
            vp[x[0]].push_back({x[1], 2});
        }

        ans[0] = 0;
        v1[0] = 1;
        v2[0] = 1;
        int temp = 1;

        for (auto x : vp[0]) {
            q.push(x);
            if (ans[x.first] == -1) {
                ans[x.first] = temp;
            }
        }

        while (!q.empty()) {
            int len = q.size();
            temp++;
            for(int i = 0; i < len; i++) {
                auto val = q.front();
                q.pop();
                if (val.second == 1) {
                    v1[val.first] = 1;
                }
                else {
                    v2[val.first] = 1;
                }

                for (auto x : vp[val.first]) {
                    if (val.second == 1 && (v2[x.first] || x.second == 1)) {
                        continue;
                    }
                    if (val.second == 2 && (v1[x.first] || x.second == 2)) {
                        continue;
                    }
                    q.push(x);                      
                    if (ans[x.first] == -1) {
                        ans[x.first] = temp;
                    }
                }
            }
        }
        return ans;
    }
};