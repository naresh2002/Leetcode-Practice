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