class Solution {
public:
    // https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/1669917/C%2B%2B-Solution-with-detailed-explanation
    
    double getMedian(vector<int> &v1, vector<int> &v2, int n, int m) { // n < m
        if (m == 0) {
            if (n % 2) {
                return v1[n / 2];
            }
            return (double)(v2[n / 2] + v2[n / 2 - 1]) / 2;
        }
        int l = 0, r = n;
        int total = n + m + 1;
        
        while (l <= r) {
            int fir = l + (r - l) / 2;
            int sec = total / 2 - fir;
            
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            if (fir > 0) {
                l1 = v1[fir - 1];
            }
            if (sec > 0) {
                l2 = v2[sec - 1];
            }
            if ((fir >= 0) && (fir < n)) {
                r1 = v1[fir];
            }
            if ((sec >= 0) && (sec < m)) {
                r2 = v2[sec];
            }
            
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else {
                    return max(l1, l2);
                }
            }
            else if (l1 > r2) {
                r = fir - 1;
            }
            else {
                l = fir + 1;
            }
        }
        return 0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n <= m) {
            return getMedian(nums1, nums2, n, m);
        }
        return getMedian(nums2, nums1, m, n);
    }
};