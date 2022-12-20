class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int charLastPosition[256] = {-1};
        for (int i = 0; i < n; i++) {
            charLastPosition[s[i]] = i;
        }
        vector<int> v;
        int ok = 1;
        v.push_back(-1);
        int maxPos = charLastPosition[s[0]];
        for (int i = 0; i < n; i++) {
            maxPos = max(maxPos, charLastPosition[s[i]]);
            if (maxPos == i || i == n - 1) {
                v.push_back(i);
                maxPos = 0;
            }
        }
        
        vector<int> ans;
        for (int i = 1; i < v.size(); i++) {
            ans.push_back(v[i] - v[i - 1]);
        }
        return ans;
    }
};