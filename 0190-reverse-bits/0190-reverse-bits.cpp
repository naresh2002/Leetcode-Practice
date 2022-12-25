class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i <= 31; i++) {
            if (n & (1 << i)) {
                ans += (1 << (31 - i));
            }
        }
        return ans;
    }
};