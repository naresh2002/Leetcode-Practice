class Solution {
public:
    vector<string> ans;
    
    void permutation (int curr, string t, int n, string s) {
        if (curr == n) {
            ans.push_back(t);
            return;
        }
        if (s[curr] >= '0' && s[curr] <= '9') {
            permutation(curr + 1, t + s[curr], n, s);
        }
        else {
            char u = toupper(s[curr]);
            char l = tolower(s[curr]);
            permutation(curr + 1, t + l, n, s);
            permutation(curr + 1, t + u, n, s);
        }
    }
    
    vector<string> letterCasePermutation(string s) {
        permutation(0, "", s.size(), s);
        return ans;
    }
};