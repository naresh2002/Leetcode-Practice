class Solution {
public:
    int find(vector<int> &v, int curr) {
        int ans = 0;
        for (auto x : v) {
            if (x == curr) {
                ans++;
                curr *= -1;
            }
        }
        return ans;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> v;
        for (int i = 1; i < n; i++) {
            int k = nums[i] - nums[i - 1];
            if (k > 0) {
                v.push_back(1);
            }
            else if (k < 0) {
                v.push_back(-1);
            }
        }
        ans = max(ans, find(v, 1) + 1);
        ans = max(ans, find(v, -1) + 1);
        return ans;        
    }
};