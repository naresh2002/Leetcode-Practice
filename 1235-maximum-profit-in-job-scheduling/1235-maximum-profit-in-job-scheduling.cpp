class Solution {
public:
    // For Daily challenge sake
    static bool compare(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    }
    
    int getNextJob(vector<vector<int>>& jobs, int idx, const int& n)
    {
        int lo = idx+1, hi = n-1, ans = n;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(jobs[idx][1] <= jobs[mid][0])
            {
                ans = mid;
                hi = mid-1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
    
    unordered_map<int, int> dp;    // Only store for relavent index
    int maxProfit(vector<vector<int>>& jobs, int idx, const int& n)
    {
        if(idx == n) return 0;

        if(dp.find(idx) != dp.end()) return dp[idx];

        // include current job and find the next job with start > curr end time
        int next = getNextJob(jobs, idx, n);  // Pick any one of the helper function
        int incl = jobs[idx][2] + maxProfit(jobs, next, n);

        // exclude current job
        int excl = maxProfit(jobs, idx+1, n);

        return dp[idx] = max(incl, excl);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));

        for(int i=0; i<n; i++)
        {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }

        sort(jobs.begin(), jobs.end(), compare);
        return maxProfit(jobs, 0, n);
    }
};