class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        for (auto c : nums) {
            if (c <= a) {
                a = c;
            }
            else if (c <= b) {
                b = c;
            }
            else {              // {a < b < c}
                return true;
            }
        }
        return false;
    }
};