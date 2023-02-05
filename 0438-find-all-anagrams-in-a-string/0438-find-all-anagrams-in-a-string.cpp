class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        int cnt[26] = {0};
        for (auto x : p) {
            cnt[x - 'a']++;
        }
        int n = s.size();
        int a[26] = {0};
        for (int i = 0; i < p.size() - 1; i++) {
            a[s[i] - 'a']++;
        }
        vector<int> ans;
        for (int l = 0, r = p.size() - 1; r < n; l++, r++) {
            a[s[r] - 'a']++;
            bool equal = true;
            for (int i = 0; i < 26; i++) {
                if (a[i] != cnt[i]) {
                    equal = false;
                    break;
                }
            }
            if (equal) {
                ans.push_back(l);
            }
            a[s[l] - 'a']--;
        }
        return ans;
    }
};