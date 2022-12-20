class Solution {
public:
    string solve (string s, int &pos) {
        int n = s.size();
        int num = 0;
        string ans;        
        for( ; pos < n; pos++) {            
            char curr = s[pos];
            if(isalpha(curr)) {
                ans += curr;
            }
            else if(isdigit(curr)) {
                num = num * 10 + curr - '0';
            }
            else if(curr == ']') {
                return ans;
            }
            else {
                string tmp = solve(s, ++pos);
                while(num--) {
                    ans += tmp;
                }
                num = 0;
            }
        }        
        return ans;
    }
    string decodeString(string s) {
        int pos = 0;
        return solve(s, pos);
    }
};