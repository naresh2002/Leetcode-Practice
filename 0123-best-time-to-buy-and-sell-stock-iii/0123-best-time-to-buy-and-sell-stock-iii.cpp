class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 2) {
            return max(0, prices[1] - prices[0]);
        }
        int n = prices.size();
        int pref[n], suff[n];
        pref[0] = 0;
        suff[n - 1] = 0;
        int buy = prices[0];
        int sell = prices[n - 1];
        
        for (int i = 1; i < n; i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            }
            pref[i] = max(pref[i - 1], prices[i] - buy);
        }
        for (int i = n - 2; i >= 0; i--) {
            if (prices[i] > sell) {
                sell = prices[i];
            }
            suff[i] = max(suff[i + 1], sell - prices[i]);
        }
        
        /*
        cout << "Pref :" << endl;
        for (int i = 0; i < n; i++) {
            cout << pref[i] << " -> ";
        }
        cout << endl;
        
        cout << "Suff :" << endl;
        for (int i = 0; i < n; i++) {
            cout << suff[i] << " <- ";
        }
        cout << endl;
        */
        
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, pref[i] + suff[i]);
        }
        return ans;
    }
};