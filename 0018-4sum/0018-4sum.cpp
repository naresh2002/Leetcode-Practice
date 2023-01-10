class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        int n = nums.size();
        
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long curr = nums[i];
                    curr += nums[j];
                    curr += nums[k];
                    curr += nums[l];
                    if (curr < target) {
                        k++;
                    }
                    else if (curr > target) {
                        l--;
                    }
                    else {
                        s.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (auto x : s) {
            ans.push_back(x);
        }
        return ans;
    }
};