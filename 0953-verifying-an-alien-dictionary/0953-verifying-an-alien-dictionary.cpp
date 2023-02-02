class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, char> m;
        for (int i = 0; i < 26; i++) {
            m[order[i]] = 'a' + i;
        }        
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                words[i][j] = m[words[i][j]];
            }
        }        
        for (int i = 1; i < words.size(); i++) {
            if (words[i] < words[i - 1]) {
                return false;
            }
        }
        return true;
    }
};