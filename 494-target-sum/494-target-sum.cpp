class Solution {
public:
    int dfs (int curr, int tot, vector<int> & v, int target) {
        if (curr == v.size()) {
            if (tot == target) {
                return 1;
            }
            return 0;
        }
        int a = dfs(curr + 1, tot + v[curr], v, target);
        int b = dfs(curr + 1, tot - v[curr], v, target);
        return a + b;
    }
    
    int findTargetSumWays(vector<int>& v, int target) {
        return dfs(0, 0, v, target);
    }
};