class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int i, int col, vector<int>& color) {
        color[i] = col;
        for(auto x: graph[i]) {
            if(color[x] == color[i]) {
                return false;
            }
            if(color[x] == 0 && !dfs(graph, x, -col, color)) {
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for(auto x : dislikes) {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> color(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(color[i] == 0 && !dfs(graph, i, 1, color)) {
                return false;
            }
        }
        return true;
    }
};