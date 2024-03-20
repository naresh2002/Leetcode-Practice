class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> prod (n, vector<int>(2, 1));
        for (int i = 1; i < n; i++) {
            prod[i][0] = prod[i - 1][0] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            prod[i][1] = prod[i + 1][1] * nums[i + 1];
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            // cout << prod[i][0] << "  (" << nums[i] << ")  " << prod[i][1] << endl;
            ans.push_back(prod[i][0] * prod[i][1]);
        }
        return ans;
    }
};