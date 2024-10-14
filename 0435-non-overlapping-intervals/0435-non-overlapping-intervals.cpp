class Solution {
public:
    static bool customComparator (vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), customComparator);
        int prev = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= intervals[prev][1]) {
                prev = i;
                cnt++;
            }
        }
        return n - cnt;
    }
};