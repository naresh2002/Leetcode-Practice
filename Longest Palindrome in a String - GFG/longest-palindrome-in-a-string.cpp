// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    int dp[1005][1005];
    
    string longestPalin (string s) {
        int n = s.size();
        int m = 0, l = 0;
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) {
                dp[i][j] = 0;
            }
        }
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if (i == j) {
                    dp[i][j] = 1;
                }
                else if (j > i) {
                    if (s[i - 1] == s[j - 1]) {
                        if (dp[i + 1][j - 1] == j - i - 1)
                            dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                if (dp[i][j] > m) {
                    m = dp[i][j];
                    l = i - 1;
                }
            }
        }
        // cout << "  -> ";
        // for (int i = 1; i <= n; i++) {
        //     cout << i << " ";
        // }
        // cout << endl;
        // for (int i = 1; i <= n; i++) {
        //     cout << i << " -> ";
        //     for (int j = 1; j <= n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return s.substr(l, m);
        
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends