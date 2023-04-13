class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int l = 0, r = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (l != r) {
                    reverse(s.begin() + l, s.begin() + r);
                }
                l = i + 1;
                r = i + 1;
            }
            else {
                r++;
            }
        }
        if (l != r) {
            reverse(s.begin() + l, s.begin() + r);
        }
        return s;
    }
};