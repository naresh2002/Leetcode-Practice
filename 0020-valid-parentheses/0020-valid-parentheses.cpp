class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(1);
            }
            else if (s[i] == '{') {
                st.push(2);
            }
            else if (s[i] == '[') {
                st.push(3);
            }
            else if (s[i] == ')') {
                if (st.size() && st.top() == 1) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else if (s[i] == '}') {
                if (st.size() && st.top() == 2) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                if (st.size() && st.top() == 3) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (st.size()) {
            return false;
        }
        return true;
    }
};