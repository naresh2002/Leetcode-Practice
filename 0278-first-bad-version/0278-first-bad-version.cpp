// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans = n;
        long long l = 1, r = n, mid;
        while (l <= r) {
            mid = (r + l) / 2;
            if (isBadVersion(mid)) {
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};