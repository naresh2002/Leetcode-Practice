class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n];
        for (auto t : times) {
            adj[t[0] - 1].push_back({t[1] - 1, t[2]}); // 0 based idxs
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k - 1});  // 0 based idxs
        vector<int> dist(n, 1e9);
        dist[k - 1] = 0;
        bool visit[n];
        memset(visit, false, sizeof(visit));
        while (!q.empty()) {
            int cost = q.top().first;
            int u = q.top().second;
            q.pop();
            visit[u] = true;
            for (auto x : adj[u]) {
                int v = x.first;
                int weight = x.second;
                if (visit[v] == false && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    q.push(make_pair(dist[v], v)); // Can also be like this
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dist[i]);
        }
        if (ans==1e9) {
            return -1;
        }
        return ans;
    }
};