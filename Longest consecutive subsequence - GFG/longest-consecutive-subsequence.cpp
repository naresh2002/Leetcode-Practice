// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int N) {
        sort(a, a + N);
        int ans = 1, curr = 1;
        for (int i = 1; i < N; i++) {
            if (a[i] == a[i - 1]) {
                continue;
            }
            if (a[i] == a[i - 1] + 1) {
                curr++;
            }
            else {
                ans = max(ans, curr);
                curr = 1;
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends