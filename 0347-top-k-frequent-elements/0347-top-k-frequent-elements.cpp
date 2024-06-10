class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m1;
        for (auto x : nums) {
            m1[x]++;
        }
        map<int, vector<int>> m2;
        for (auto x : m1) {
            m2[-1 * x.second].push_back(x.first);
        }
        vector<int> ans;
        for (auto x : m2) {
            for (auto y : x.second) {
                ans.push_back(y);
                k--;
                if (k == 0) {
                    return ans;
                }
            }
        }
        return ans;
    }
};