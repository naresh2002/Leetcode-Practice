class Solution {
public:
    string solve(vector<int> &v) {
        string s;
        if (v.size() == 1) {
            s+= to_string(v[0]);
        }
        else {
            s += to_string(v[0]);
            s += "->";
            s += to_string(v[v.size() - 1]);
        }
        return s;
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return {};
        }
        vector<string> ans;
        vector<int> v;
        v.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                v.push_back(nums[i]);
            }
            else {
                ans.push_back(solve(v));
                v.clear();
                v.push_back(nums[i]);
            }
        }
        if (v.size()) {
            ans.push_back(solve(v));
        }
        return ans;
    }
};