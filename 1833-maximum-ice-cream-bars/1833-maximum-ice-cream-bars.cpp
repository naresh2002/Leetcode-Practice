class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0, pref = 0;
        for (auto x : costs) {
            if (pref + x <= coins) {
                pref += x;
                ans++;
            }
            else {
                break;
            }
        }
        return ans;
    }
};