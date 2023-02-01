class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int ans = 10;   // FOR n = 1
        for (int i = 2; i <= n; i++) {
            int k = 9;
            int temp = 9;   // For biggest unit place like '_'_ _ _
            for (int j = 1; j < i; j++) {
                temp *= k;
                k--;
            }
            ans += temp;
        }
        return ans;
    }
};