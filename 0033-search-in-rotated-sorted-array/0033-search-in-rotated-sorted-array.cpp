class Solution {
public:
    //  https://leetcode.com/problems/search-in-rotated-sorted-array/dis
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = (l + r) / 2;
            int temp;
            if (target < nums[0] == nums[mid] < nums[0]) {
                temp = nums[mid];
            }
            else {
                if (target < nums[0]) {
                    temp = -1e6;
                }
                else {
                    temp = 1e6;
                }
            }
            if (temp < target) {
                l = mid + 1;
            }
            else if (temp > target) {
                r = mid;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};