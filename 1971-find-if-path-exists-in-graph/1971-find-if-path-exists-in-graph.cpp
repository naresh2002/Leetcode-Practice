class Solution {    // DISJOINT SET UNION
    int parent[200000];
    void make_set(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find_set(int curr) {
        if (parent[curr] == curr) {
            return curr;
        }
        parent[curr] = find_set(parent[curr]);
        return parent[curr];
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b] = a;
        }
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        make_set(n);
        for (auto edge : edges) {
            union_set(edge[0], edge[1]);
        }
        return find_set(source) == find_set(destination);
    }
};