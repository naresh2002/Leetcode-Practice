class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> firstOccurence (26, -1);
        vector<int> lastOccurence (26, -1);
        for (int i = 0; i < n; i++) {
            if (firstOccurence[s[i] - 'a'] == -1) {
                firstOccurence[s[i] - 'a'] = i;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (lastOccurence[s[i] - 'a'] == -1) {
                lastOccurence[s[i] - 'a'] = i;
            }
        }
        vector<int> ans;
        int curr = 0;
        int last = -1;
        for (int i = 0; i < n; i++) {
            curr = max(curr, lastOccurence[s[i] - 'a']);
            if (curr == i) {
                ans.push_back(curr - last);
                last = i;
            }
        }
        return ans;
    }
};