class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        return max_element(v.begin(), v.end()) - v.begin();
    }
};