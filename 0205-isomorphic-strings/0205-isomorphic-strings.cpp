class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m1, m2;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (m1.count(s[i]) || m2.count(t[i])) {
                if (m1[s[i]] != t[i] || m2[t[i]] != s[i]) {
                    return false;
                }
            }
            else {
                m1[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
        }
        return true;
    }
};