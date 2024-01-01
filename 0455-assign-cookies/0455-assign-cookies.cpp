class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int n = g.size();
        int j = 0, m = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && s[j] < g[i]) {
                j++;
            }
            if (j >= m) {
                break;
            }
            if (g[i] <= s[j]) {
                ans++;
                j++;
            }
        }
        
        return ans;
    }
};