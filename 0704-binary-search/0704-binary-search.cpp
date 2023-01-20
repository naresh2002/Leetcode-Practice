class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                ans = mid;
                break;
            }
            if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};