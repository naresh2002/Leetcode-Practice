class Solution {    // DISJOINT SET UNION
    int parent[1001];
    void make_set (int n) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find_set (int a) {
        if (parent[a] == a) {
            return a;
        }
        parent[a] = find_set(parent[a]);
        return parent[a];
    }
    
    void union_set (int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b] = a;
        }
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        make_set(n);
        vector<int> ans;
        for (auto edge : edges) {
            if (find_set(edge[0]) == find_set(edge[1])) { // Always use find_set() to find parent, not parent[i]
                ans = edge;
            }
            union_set(edge[0], edge[1]);
        }
        if (!ans.size()) {
            ans = edges[n - 1];
        }
        return ans;
    }
};