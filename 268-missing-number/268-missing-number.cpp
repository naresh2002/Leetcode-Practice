class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s = 0;
        for (auto x : nums) {
            s += x;
        }
        return ((nums.size() * (nums.size() + 1)) / 2) - s;
    }
};