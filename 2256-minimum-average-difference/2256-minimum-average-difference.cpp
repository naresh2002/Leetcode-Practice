class Solution {
public:
    int minimumAverageDifference(vector<int>& v) {
        int n = v.size();
        long long lSum = 0, rSum = 0;
        for (int i = 0; i < n; i++) {
            rSum += v[i];
        }
        int ans = -1, diff = INT_MAX;
        for (int i = 0; i < n; i++) {
            lSum += v[i];
            rSum -= v[i];
            int l = round(lSum / (i + 1));
            int r = i < n - 1 ? round(rSum / (n - i - 1)) : 0;            
            if (abs(l - r) < diff) {
                ans = i;
                diff = abs(l - r);
            }
        }
        return ans;
    }
};