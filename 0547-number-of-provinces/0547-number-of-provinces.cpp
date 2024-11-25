class Solution {
    int parent[202];
    void make_set(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find_set(int a) {
        if (parent[a] == a) {
            return a;
        }
        parent[a] = find_set(parent[a]);
        return parent[a];
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b] = a;
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        make_set(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j]) {
                    union_set(i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (find_set(i) == i) {
                ans++;
            }
        }
        return ans;
    }
};