class Solution {
public:
    vector<int> adj[2005];       // Array of vector
    unordered_map<int, int> vis;
    unordered_map<int, int> done;
    
    bool cyclic(int n) {
        if (done[n]) {  // Prevent TLE
            return false;
        }
        vis[n] = done[n] = 1;
        bool cycle = false;
        for (auto x : adj[n]) {
            if (vis[x]) {
                cycle = true;
            }
            else {
                if (cyclic(x)) {
                    cycle = true;
                }
            }
            if (cycle) {
                break;
            }
        }
        vis[n] = 0;
        return cycle;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto x : prerequisites) {
            adj[x[0]].push_back(x[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (cyclic(i)) {
                return false;
            }
        }
        return true;
    }
};