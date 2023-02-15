class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        reverse(num.begin(), num.end());
        vector<int> v;
        while (k) {
            v.push_back(k % 10);
            k /= 10;
        }
        int m = v.size();
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int temp = num[i] + carry;
            if (i < m) {
                temp += v[i];
            }
            num[i] = temp % 10;
            carry = temp / 10;
        }
        for (int i = n; i < m; i++) {
            int temp = v[i] + carry;
            num.push_back(temp % 10);
            carry = temp / 10;
        }
        while (carry) {
            num.push_back(carry % 10);
            carry /= 10;
        }
        reverse(num.begin(), num.end());
        return num;
    }
};