class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> m;
        int left = 0, right = 0;
        int ans = 0;
        
        while (right < n) {
            m[fruits[right]]++;
            if (m.size() > 2) {
                m[fruits[left]]--;
                if (m[fruits[left]] == 0) {
                    m.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        
        return ans;
    }
};