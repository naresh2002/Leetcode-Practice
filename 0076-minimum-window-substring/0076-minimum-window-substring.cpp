class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int cnt = 0, minLength = INT_MAX;
        int l = 0, r = 0;
        int idx = -1;
        unordered_map<char, int> m;
        for (auto x : t) {
            m[x]++;
        }
        while (r < n) {
            if (m[s[r]] > 0) {
                cnt++;
            }
            m[s[r]]--;
            while (cnt == t.size()) {
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    idx = l;
                }
                m[s[l]]++;
                if (m[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        if (idx == -1) {
            return "";
        }
        return s.substr(idx, minLength);
    }
};