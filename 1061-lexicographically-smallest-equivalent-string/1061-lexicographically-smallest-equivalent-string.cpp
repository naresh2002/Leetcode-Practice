class Solution {
public:
    int parent[256];
    int find(int ch) {
        if (parent[ch] == 0) {
            return ch;
        }
        parent[ch] = find(parent[ch]);
        return parent[ch];
    }
    
    void Union(int ch1, int ch2) {
        ch1 = find(ch1);
        ch2 = find(ch2);
        if (ch1 != ch2) {
            parent[max(ch1, ch2)] = min(ch1, ch2);
        }
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < s1.size(); i++) {
            Union(s1[i], s2[i]);
        }
        string ans;
        for (int i = 0; i < baseStr.size(); i++) {
            ans += find(baseStr[i]);
        }
        return ans;
    }
};