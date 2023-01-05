class Solution {
public:
    static bool comp(vector<int>&v1, vector<int>& v2) {
        return v1[1] < v2[1];
    }    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), comp);
        int last = points[0][1];
        int ans = 1;
        for (int i = 1; i < n; i++) {
            if (points[i][0] > last) {
                ans++;
                last = points[i][1];
            }
        }
        return ans;
    }
};