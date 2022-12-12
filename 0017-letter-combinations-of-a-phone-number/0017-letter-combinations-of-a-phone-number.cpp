class Solution {
public:
    vector<string> ans;
    void solve (string str, vector<vector<char>> &v, int pos, string &digits, int n) {
        if (pos == n) {
            ans.push_back(str);
            return;
        }
        for (int i = 0; i < v[digits[pos] - '2'].size(); i++) {
            solve(str + v[digits[pos] - '2'][i], v, pos + 1, digits, n);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }
        vector<vector<char>> v;
        v.push_back({'a', 'b', 'c'});
        v.push_back({'d', 'e', 'f'});
        v.push_back({'g', 'h', 'i'});
        v.push_back({'j', 'k', 'l'});
        v.push_back({'m', 'n', 'o'});
        v.push_back({'p', 'q', 'r', 's'});
        v.push_back({'t', 'u', 'v'});
        v.push_back({'w', 'x', 'y', 'z'});
        
        solve("", v, 0, digits, digits.size());
        return ans;
    }
};