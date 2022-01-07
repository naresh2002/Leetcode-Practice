class Solution {
public:
  int convert (string s) {
    // int n = s.size();
    // int ans = 0;
    // if (s[0] = '-') {
    //   for (int i = 1; i < n; i++) {
    //     ans *= 10;
    //     ans += s[i] - '0';
    //   }
    //   return -ans;
    // }
    // for (int i = 0; i < n; i++) {
    //   ans *= 10;
    //   ans += s[i] - '0';
    // }
    return stoi(s);
  }
  
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    int n = tokens.size();
    if (n == 1) {
      return (convert(tokens[0]));
    }
    
    for (int i = 0; i < n; i++) {
      string temp = tokens[i];
      if (temp == "+") {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        s.push(a + b);
      }
      else if (temp == "-") {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        s.push(a - b);
      }
      else if (temp == "*") {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        s.push(a * b);
      }
      else if (temp == "/") {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();
        s.push(a / b);
      }
      else {
        s.push(convert(temp));
      }
    }
    return s.top();
  }
};

