class Solution {
public:
    int ans;
    void dfs (int curr, int tot, vector<int> & v, int target) {
        if (curr == v.size()) {
            if (tot == target) {
                ans++;
            }
            return;
        }
        dfs(curr + 1, tot + v[curr], v, target);
        dfs(curr + 1, tot - v[curr], v, target);
    }
    
    int findTargetSumWays(vector<int>& v, int target) {
        dfs(0, 0, v, target);
        return ans;
    }
};