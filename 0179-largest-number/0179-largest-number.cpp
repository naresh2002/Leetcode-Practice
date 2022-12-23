class Solution {
public:
    //  COMPARATOR
    bool static comp(string s1, string s2) {
        return (s1 + s2) > (s2 + s1);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto x : nums) {
            v.push_back(to_string(x));
        }
        sort(v.begin(), v.end(), comp);
                            // OR
        // sort(begin(arr), end(arr), [](string &s1, string &s2){return s1+s2>s2+s1;});
        string temp;
        for (auto x : v) {
            temp += x;
        }
        int k = 0;
        while (temp[k] == '0') {
            k++;
        }
        string ans = temp.substr(k);
        if (ans.size() == 0) {
            return "0";
        }
        return ans;
    }
};