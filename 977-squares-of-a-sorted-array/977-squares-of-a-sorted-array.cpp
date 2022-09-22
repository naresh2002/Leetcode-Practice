class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        vector<int> ans;
        int l = 0, r = v.size() - 1;
        while (l <= r) {
            if (abs(v[l]) >= abs(v[r])) {
                ans.push_back(v[l] * v[l]);
                l++;
            }
            else {
                ans.push_back(v[r] * v[r]);
                r--;                
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};