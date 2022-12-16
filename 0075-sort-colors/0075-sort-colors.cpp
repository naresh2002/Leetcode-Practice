class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n =nums.size();
        int a[3] = {0};
        for (int i = 0; i < n; i++) {
            a[nums[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (a[0]) {
                nums[i] = 0;
                a[0]--;
            }
            else if (a[1]) {
                nums[i] = 1;
                a[1]--;
            }
            else {
                nums[i] = 2;
            }
        }
    }
};