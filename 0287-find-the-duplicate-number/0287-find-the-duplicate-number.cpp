class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        for (int i = 0; i < n; i++) {
            while (nums[i] != i + 1) {
                prev = nums[i];
                swap(nums[i], nums[nums[i] - 1]);
                if (nums[i] == prev) {
                    return nums[i];
                }
            }
        }
        return nums[n - 1];
    }
};

/*
// SOLUTION 2 :
class Solution {
public:
    int findDuplicate(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n; i++) {
            int idx = v[i] % n;
            if (v[idx] / n == 1) {
                return idx;
            }
            v[idx] += n;
        }
        return -1;
    }
};
*/