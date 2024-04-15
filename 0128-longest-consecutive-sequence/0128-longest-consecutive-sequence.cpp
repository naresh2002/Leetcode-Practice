class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto x : nums) {
            m[x] = 1;
        }
        vector<int> v;
        for (auto x : m) {
            if (m.find(x.first - 1) != m.end()) {
                m[x.first] = 0; // This cannot be starting point of required sequence
            }
        }
        int ans = 0;
        for (auto x : m) {
            int k = 0;
            if (x.second) {
                while (m.find(x.first + k) != m.end()) {
                    k++;
                }
            }
            ans = max(ans, k);
        }
        
        return ans;
    }
};