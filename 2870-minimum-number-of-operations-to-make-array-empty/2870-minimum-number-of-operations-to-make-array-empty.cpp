class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> m;
        for (auto x : nums) {
            m[x]++;
        }
        for (auto x : m) {
            if (x.second < 2) {
                return -1;
            }
        }
        
        int ans = 0;
        for (auto x : m) {
            ans += (x.second / 3);
            if (x.second % 3) {
                ans++;
            }
        }
        return ans;
    }
};