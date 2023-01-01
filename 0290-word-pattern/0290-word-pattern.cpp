class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, set<string>> m1;
        map<string, set<char>> m2;
        int k = 0;
        string str;
        for (int i = 0; i <= s.size(); i++) {
            if (k == pattern.size()) {
                return false;
            }
            if (i == s.size() || s[i] == ' ') {
                m1[pattern[k]].insert(str);
                m2[str].insert(pattern[k]);
                if (m1[pattern[k]].size() > 1 || m2[str].size() > 1) {
                    return false;
                }
                k++;
                str = "";
                continue;
            }
            str += s[i];
        }
        if (k != pattern.size()) {
            return false;
        }
        return true;
    }
};