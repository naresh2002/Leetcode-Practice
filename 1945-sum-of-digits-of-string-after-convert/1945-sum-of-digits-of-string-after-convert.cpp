class Solution {
public:
    int solve(string s, int k) {
        if (k == 0) {
            return stoi(s);
        }
        int ans = 0;
        for (auto x : s) {
            ans += (x - '0');
        }
        return solve(to_string(ans), k - 1);
    }
    
    int getLucky(string s, int k) {
        string temp;
        for (auto x : s) {
            int p = (x - 'a' + 1);
            temp += to_string(p);
        }
        return solve(temp, k);
    }
};