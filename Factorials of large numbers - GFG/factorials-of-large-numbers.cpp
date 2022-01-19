// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    void multiply(int n, vector<int> &v) {
        int carry = 0;
        for (int i = 0; i < (int)v.size(); i++) {
            int temp = v[i] * n + carry;
            v[i] = temp % 10;
            carry = temp / 10;
        }
        while (carry) {
            v.push_back(carry % 10);
            carry /= 10;
        }
    }
    
    vector<int> factorial(int N){
        vector<int> ans;
        int n = 1, carry = 0;
        ans.push_back(1);
        for (int i = 2; i <= N; i++) {
            multiply(i, ans);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends