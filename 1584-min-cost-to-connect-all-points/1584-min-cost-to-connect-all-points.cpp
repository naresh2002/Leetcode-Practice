class Solution {
public:
    int parent[1001];
    
    // Kruskal
    int find(int a) {
        if(parent[a] < 0) {
            return a;
        }
        
        return parent[a] = find(parent[a]);
    }
    
    void Union(int a, int b) {
        parent[a] = b;
    }
    
    int minCostConnectPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            parent[i] = -1;
        }
        
        vector<pair<int, pair<int, int>>> adj;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int weight = abs(arr[i][0] - arr[j][0]) + abs(arr[i][1] - arr[j][1]); // Manhattan Dist.
                adj.push_back({weight, {i, j}}); // {Dist, {Idx1, Idx2}}
            }
        }
        
        sort(adj.begin(), adj.end());
        int sum = 0;
        
        for(int i = 0; i < adj.size(); i++) {
            int a = find(adj[i].second.first);
            int b = find(adj[i].second.second);
            
            if(a != b) { // Both's idx are not same
                sum += adj[i].first;
                Union(a, b);
            }
        }
        
        return sum;
    }
};