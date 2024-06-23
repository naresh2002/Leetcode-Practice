class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = nums[0];
        int l = 0, r = nums.size() - 1;
        if (nums[0] <= nums[r]) {
            return nums[0];
        }
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= nums[0]) {
                l = mid + 1;
            }
            else {
                ans = nums[mid];
                r = mid - 1;
            }
        }
        return ans;
    }
};