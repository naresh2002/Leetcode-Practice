class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int sz = original.size();
        if (m * n != sz) {
            return {};
        }
        vector<vector<int>> ans;
        vector<int> v;
        for (int i = 0; i < sz; i++) {
            v.push_back(original[i]);
            if (v.size() == n) {
                ans.push_back(v);
                v.clear();
            }
        }
        return ans;
    }
};