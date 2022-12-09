class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxJump = 0;
        for (int i = 0; i < n - 1; i++) {
            maxJump = max(maxJump, nums[i]);
            if (maxJump == 0) {
                return false;
            }
            maxJump--;
        }
        return true;
    }
};