class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int cnt[205] = {0};
        int maxCount = 0;
        for (auto x : nums) {
            cnt[x]++;
            maxCount = max(maxCount, cnt[x]);
        }
        
        vector<vector<int>> ans;
        for (int i = maxCount; i > 0; i--) {
            vector<int> v;
            for (int j = 0; j < 205; j++) {
                if (cnt[j] == i) {
                    v.push_back(j);
                    cnt[j]--;
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};