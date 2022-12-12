class Solution {
public:
    //  https://leetcode.com/problems/3sum/discuss/792264/Simple-C%2B%2B-Optimized-solution-oror-handle-duplicate-edge-case-also-oror-O(n2)ororcpp
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3 || nums[0] > 0) {
            return {};
        }
        set<vector<int>> s;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] + nums[i] == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    l++;
                    r--;
                }
                else if (nums[l] + nums[r] + nums[i] < 0) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return ans;
    }
};