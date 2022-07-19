class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1]) {
                return mid;
            }
            else if (v[mid - 1] < v[mid] && v[mid] < v[mid + 1]) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        return 0;
    }
};