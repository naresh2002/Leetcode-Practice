class Solution {
public:
    // Good Explanation : https://leetcode.com/problems/minimum-height-trees/discuss/1630864/C%2B%2B-EASY-TO-SOLVE-oror-Detailed-Explanation-with-dry-run
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> degree (n, 0);
        vector<int> adj[n];
        for (auto edge : edges) {
            degree[edge[0]]++;
            degree[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<int> degreeOneNodes;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                degreeOneNodes.push(i);
            }
        }
        vector<int> ans;
        while (!degreeOneNodes.empty()) {
            int n = degreeOneNodes.size();
            ans.clear();
            
            // This is our level order traverse
            while (n--) {
                int curr = degreeOneNodes.front();
                degreeOneNodes.pop();
                ans.push_back(curr);
                int currSize = adj[curr].size();
                for (int i = 0; i < currSize; i++) {
                    degree[adj[curr][i]]--;
                    if (degree[adj[curr][i]] == 1) {
                        degreeOneNodes.push(adj[curr][i]);
                    }
                }
            }
        }
        return ans;
    }
};