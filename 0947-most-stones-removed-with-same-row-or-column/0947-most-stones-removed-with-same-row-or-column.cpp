class Solution {
    int parent[10004];
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
    
    void union_set(int a, int b, pair<int, int> c1, pair<int, int> c2) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (c1 <= c2) {
                parent[b] = a;
            }
            else {
                parent[a] = b;
            }
        }
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        make_set(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x1 = stones[i][0];
                int x2 = stones[j][0];
                int y1 = stones[i][1];
                int y2 = stones[j][1];
                if (x1 == x2 || y1 == y2) {
                    union_set(i, j, {x1, y1}, {x2, y2});
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (find_set(i) != i) {
                ans++;
            }
        }
        return ans;
    }
};