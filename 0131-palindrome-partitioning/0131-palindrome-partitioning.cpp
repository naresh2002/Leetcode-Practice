class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &s, int l, int r) {
        for (; l <= r; l++, r--) {
            if (s[l] != s[r]) {
                return false;
            }
        }
        return true;
    }
    
    void dfs(int pos, int n, vector<string> &v, string &s) {
        if (pos == n) {
            ans.push_back(v);
            return;
        }
        for (int i = pos; i < n; i++) {
            if (isPalindrome(s, pos, i)) {
                v.push_back(s.substr(pos, i - pos + 1));
                dfs(i + 1, n, v, s);
                v.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> v;
        dfs(0, s.size(), v, s);
        return ans;
    }
};