class Solution {
public:
    long long factorial(int n) {
        long long ans = 1;
        for (int i = 2; i <= n; i++) {
            ans *= i;
        }
        return ans;
    }
    
    // To store all k-palindromic numbers
    void solve (int curr, int n, string &s, set<string> &v, int k) {
        if (curr == n) {
            long long p = 0;
            for (int i = 0; i < s.size(); i++) {
                p *= 10;
                p += (s[i] - '0');
            }
            if (s[0] != '0' && p % k == 0) {
                string ss = s;
                sort(ss.begin(), ss.end());
                v.insert(ss);
            }
            return;
        }
        // To make number palindrome last half characters need to be fixed
        if (curr >= (n + 1) / 2) {
            s += s[n - curr - 1];
            solve(curr + 1, n, s, v, k);
            s.pop_back();
            return;
        }
        for (char ch = '0'; ch <= '9'; ch++) {
            s += ch;
            solve(curr + 1, n, s, v, k);
            s.pop_back();
        }
    }

    long long countGoodIntegers(int n, int k) {
        set<string> v;
        string s;
        solve(0, n, s, v, k);
        long long ans = 0;
        for (auto x : v) {
            map<char, int> m;
            for (auto y : x) {
                m[y]++;
            }
            // All possible permutations
            long long a = factorial(n);
            for (auto x : m) {
                a /= factorial(x.second);
            }
            // Removing permutations for leading zero
            if (m.find('0') != m.end()) {
                long long b = factorial(n - 1);
                for (auto x : m) {
                    if (x.first == '0') {
                        b /= factorial(x.second - 1);
                    }
                    else {
                        b /= factorial(x.second);
                    }
                }
                a -= b;
            }
            
            ans += a;
        }
        return ans;
    }
};