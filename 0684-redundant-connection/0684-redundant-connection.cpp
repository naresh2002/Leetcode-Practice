class Solution {    // DISJOINT SET UNION
    int parent[1001];
    
    void make_set(int n) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find_set(int k) {
        if (parent[k] == k) {
            return k;
        }
        parent[k] = find_set(parent[k]);
        return parent[k];
    }
    
    void union_set(int a, int b) {
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
            if (find_set(edge[0]) == find_set(edge[1])) {
                ans = edge;
            }
            if (ans.size()) {
                break;
            }
            union_set(edge[0], edge[1]);
        }
        if (!ans.size()) {
            ans = edges[n - 1];
        }
        return ans;
    }
    
};