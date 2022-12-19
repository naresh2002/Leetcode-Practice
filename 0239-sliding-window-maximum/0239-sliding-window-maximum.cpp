class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftmax (n), rightmax (n);
        for (int i = 0; i < n; i++) {
            if (i % k == 0) {
                leftmax[i] = nums[i];
                continue;
            }
            leftmax[i] = max(leftmax[i - 1], nums[i]);
        }
        rightmax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if ((i + 1) % k == 0) {
                rightmax[i] = nums[i];
                continue;
            }
            rightmax[i] = max(rightmax[i + 1], nums[i]);
        }
        vector<int> ans;
        for (int i = 0; i < n - k + 1; i++) {
            int temp = max(leftmax[i + k - 1], rightmax[i]);
            ans.push_back(temp);
        }
        return ans;
    }
};