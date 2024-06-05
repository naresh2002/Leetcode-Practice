class Solution {
public:
    // MOORE'S VOTING ALGORITHM
    
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 0;
        for (auto x : nums) {
            if (count) {
                if (x == majority) {
                    count++;
                }
                else {
                    count--;
                }
            }
            else {
                majority = x;
                count = 1;
            }
        }
        return majority;
    }
};