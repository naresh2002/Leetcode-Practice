class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        ans.push_back(nums);
        int n = nums.size();
        while (1) {
            int pos = -1;
            for (int i = n - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                break;
            }
            for (int i = n - 1; i > pos; i--) {
                if (nums[i] > nums[pos]) {
                    swap(nums[i], nums[pos]);
                    reverse(nums.begin() + pos + 1, nums.end());
                    ans.push_back(nums);
                    break;
                }
            }
        }
        return ans;
    }
};