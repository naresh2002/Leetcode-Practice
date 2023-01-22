class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &s, int l, int r) {
        while (l <= r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    void dfs(int curr, int n, string s, vector<string> &v) {
        if (curr == n) {
            ans.push_back(v);
            return;
        }
        for (int i = curr; i < n; i++) {
            if (isPalindrome(s, curr, i)) {
                v.push_back(s.substr(curr, i - curr + 1));
                dfs(i + 1, n, s, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> v;
        dfs(0, n, s, v);
        return ans;
    }
};