class Solution {
public:
    bool gcdFound(string &s, string &str1, string &str2) {
        int n = s.size();
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != s[i % n]) {
                return false;
            }
        }
        for (int i = 0; i < str2.size(); i++) {
            if (str2[i] != s[i % n]) {
                return false;
            }
        }
        return true;
    }
    
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        string s;
        for (int i = min(n, m); i > 0; i--) {
            s = str1.substr(0, i);
            int sz = s.size();
            // cout << s << " " << sz << endl;
            if (n % sz == 0 && m % sz == 0) {
                if (gcdFound(s, str1, str2)) {
                    return s;
                }
            }
        }
        return "";
    }
};