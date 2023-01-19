class Solution {
public:
    // NICE APPROACH (like from 1st modGroup[p] to next modGroup[p] subarray sum will be divisible by k)
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixMod = 0;
        int ans = 0;
        
        vector<int> modGroups(k);
        modGroups[0] = 1;
        for (auto x : nums) {
            prefixMod = (prefixMod + x) % k;
            if (prefixMod < 0) {
                prefixMod += k;
            }
            ans += modGroups[prefixMod];
            modGroups[prefixMod]++;
        }
        
        return ans;
    }
};