class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            long long k = (success + spells[i] - 1) / spells[i];
            int temp = lower_bound(potions.begin(), potions.end(), k) - potions.begin();
            ans.push_back(m - temp);
        }
        return ans;
    }
};