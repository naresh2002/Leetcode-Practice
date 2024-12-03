class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int totalPossible = 1;
        queue<int> q;
        vector<bool> vis (n, false);
        vis[0] = true;
        q.push(0);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto x : rooms[curr]) {
                if (!vis[x]) {
                    q.push(x);
                    vis[x] = true;
                    totalPossible++;
                }
            }
        }
        return totalPossible == n;
    }
};