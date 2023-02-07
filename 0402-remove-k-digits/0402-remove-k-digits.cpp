class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(auto x : num) {
            while(ans.size() && ans.back() > x && k) {
                ans.pop_back();
                k--;
            }
            if(ans.size() || x != '0') {
                ans.push_back(x);
            }
        }
        while(ans.size() && k--) {
            ans.pop_back();
        }
        if (!ans.size()) {
            return "0";
        }
        return ans;
    }
};

/*
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for (auto x : num) {
            if (st.size() && k && st.top() > x) {
                st.pop();
                k--;
            }
            if (x != '0' || st.size()) {
                st.push(x);
            }
        }
        while (st.size() && k) {
            st.pop();
            k--;
        }
        string ans;
        while (st.size()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        if (ans.size()) {
            return ans;
        }
        return "0";
    }
};
*/