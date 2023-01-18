class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum = 0;
        int curr_sum1 = 0, curr_sum2 = 0;
        int mxsum_subary = INT_MIN;
        int minsum_subary = INT_MAX;
        
        for(auto x : nums) {
            total_sum += x;
            curr_sum1 += x;
            curr_sum2 += x;
            
            mxsum_subary = max(mxsum_subary, curr_sum1);
            if (curr_sum1 < 0) {
                curr_sum1 = 0;
            }
            
            minsum_subary = min(curr_sum2, minsum_subary);
            if(curr_sum2 > 0) {
                curr_sum2 = 0;
            }
        }
        int ans = 0;
        if (total_sum == minsum_subary) {
            ans = mxsum_subary;
        }
        else {
            ans = max(mxsum_subary, total_sum - minsum_subary);
        }
        return ans;
    }
};

/*
// WRONG
class Solution {
public:
    int minSumSubarray(vector<int> &nums, int n) {
        int best = 1e6;
        int curr = 1e6;
        for (int i = 0; i < n; i++) {
            curr = min(nums[i], curr + nums[i]);
            best = min(best, curr);
        }
        return best;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int tot = 0;
        accumulate(nums.begin(), nums.end(), tot);
        int ans = tot - minSumSubarray(nums, n);
        int curr = -1e6;
        for (int i = 0; i < n; i++) {
            curr = max(nums[i], curr + nums[i]);
            ans = max(ans, curr);
        }
        return ans;
    }
};
*/