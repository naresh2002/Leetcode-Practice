class Solution {
public:
    string addBinary(string a, string b) {
        int n = min(a.size(), b.size());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans;
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i] - '0';
            int y = b[i] - '0';
            int temp = x + y + carry;
            if (temp > 1) {
                ans += (temp % 2 + '0');
                carry = 1;
            }
            else {
                ans += (temp + '0');
                carry = 0;
            }
        }
        for (int i = n; i < a.size(); i++) {
            int x = a[i] - '0';
            int temp = x + carry;
            if (temp > 1) {
                ans += (temp % 2 + '0');
                carry = 1;
            }
            else {
                ans += (temp + '0');
                carry = 0;
            }
        }
        for (int i = n; i < b.size(); i++) {
            int y = b[i] - '0';
            int temp = y + carry;
            if (temp > 1) {
                ans += (temp % 2 + '0');
                carry = 1;
            }
            else {
                ans += (temp + '0');
                carry = 0;
            }
        }
        if (carry) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};