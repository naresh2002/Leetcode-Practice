class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totGas = 0, totCost = 0;
        int curr = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            totGas += gas[i];
            totCost += cost[i];
            curr += (gas[i] - cost[i]);
            if (curr < 0) {
                ans = i + 1;    // Since it is guranteed that solution exists
                curr = 0;
            }
        }
        if (totGas < totCost) {
            return -1;
        }
        return ans;
    }
};