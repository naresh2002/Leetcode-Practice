class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref;
        pref.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            pref.push_back(pref.back() + nums[i]);
        }
        return pref;
    }
};