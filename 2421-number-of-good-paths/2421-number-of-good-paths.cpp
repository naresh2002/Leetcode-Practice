/*
const int N = 30005;
vector<int> adj[N];
int par[N], val[N], cnt[N];

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        for (int i = 0; i <= n; i++) adj[i].clear();
        
        for (auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        map<int,vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[vals[i]].push_back(i);
        }
        
        int ans = 0;
        for (auto x : m) {
            // cout << "for val = " << x.first << endl;
            set<int> s;
            auto v = x.second;
            for (auto y : v) {
                // cout << "make "<< y << endl;
                make(y, vals[y]);
                s.insert(y);
            }
            for (auto cur : v) {
                for (auto neg : adj[cur]) {
                    if (vals[neg] <= vals[cur]) {
                        // cout << "union " << neg << " " << cur << endl;
                        unionset(neg, cur);
                        int leader = findParent(cur);
                        // cout << "set insert " << leader << " with val = " << val[leader] << " cnt = " << cnt[leader] << endl;;
                        s.insert(leader);
                    }
                }
            }
            for (auto x : s) if (x == findParent(x)) {
                ans += cnt[x] * (cnt[x] + 1) / 2;
            }
        }
        
        return ans;
        
    }
};
*/

const int N = 30005;
class Solution {
public:    
    int par[N], val[N], cnt[N];

    void make(int n, int value) {
        par[n] = n;
        val[n] = value;
        cnt[n] = 1;
    }
    
    int find(int n) {
        if (par[n] == n) {
            return n;
        }
        par[n] = find(par[n]);
        return par[n];
    }
    
    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (val[a] > val[b]) {
                val[b] = val[a];
                cnt[b] = cnt[a];
            }
            else if (val[a] == val[b]) {
                cnt[b] += cnt[a];
            }
            par[a] = b;
        }
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        map<int, vector<int>> m;
        for (int i = 0; i < n; i++) {
            m[vals[i]].push_back(i);
        }
        int ans = 0;
        for (auto x : m) {
            set<int> s;
            auto v = x.second;
            for (auto y : v) {
                make(y, vals[y]);
                s.insert(y);
            }
            for (auto cur : v) {
                for (auto neighbor : adj[cur]) {
                    if (vals[neighbor] <= vals[cur]) {
                        Union(neighbor, cur);
                        int leader = find(cur);
                        s.insert(leader);
                    }
                }
            }
            for (auto x : s) {
                if (x == find(x)) {
                    ans += cnt[x] * (cnt[x] + 1) / 2;
                }
            }
        }
        
        return ans;
    }
    /*
    int dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vals, int value) {
        if (vals[node] > value || node == parent) {
            return 0;
        }
        int ans = 0;
        for (auto x : adj[node]) {
            if (x == parent) {
                continue;
            }
            ans += dfs(x, node, adj, vals, value);
        }
        if (vals[node] == value) {
            ans++;
        }
        return ans;
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto x : edges) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        map<int, int> m;
        vector<int> v;
        for (auto x : vals) {
            m[x]++;
            if (m[x] > 1)
        }
        int ans = vals.size();
        for (auto x : m) {
            if (x.second > 1) {
                for (auto y : adj[x.first]) {
                    // cout << x.first << endl;
                    // cout << y << endl;
                    // cout << x.first << endl;
                    // cout << vals[x.first] << endl << endl;
                    ans += dfs(y, x.first, adj, vals, vals[x.first]);
                }
            }
        }
        return ans;
    }
    */
};