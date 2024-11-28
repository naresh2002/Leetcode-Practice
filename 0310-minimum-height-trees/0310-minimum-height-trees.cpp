class Solution {
public:
   // Good Explanation : https://leetcode.com/problems/minimum-height-trees/discuss/1630864/C%2B%2B-EASY-TO-SOLVE-oror-Detailed-Explanation-with-dry-run
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> degree(n, 0);
        vector<int> adj[n];
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()) {
            int sz = q.size();
            ans.clear();
            while (sz--) {
                int curr = q.front();
                q.pop();
                degree[curr]--;
                ans.push_back(curr);
                for (auto x : adj[curr]) {
                    degree[x]--;
                    if (degree[x] == 1) {
                        q.push(x);
                    }
                }
            }
        }
        return ans;
    }
};