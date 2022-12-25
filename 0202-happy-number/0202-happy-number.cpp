class Solution {
public:
    bool isHappy(int n) {
        int cnt = 0;
        while (n != 1) {
            if (cnt == 100) {
                return false;
            }
            int temp = 0;
            while (n) {
                temp += pow((n % 10), 2);
                n /= 10;
            }
            n = temp;
            cnt++;
        }
        return true;
    }
};