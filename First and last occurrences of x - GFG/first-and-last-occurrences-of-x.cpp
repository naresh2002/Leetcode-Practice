// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int a[], int n , int x )
{
    // code here
    auto l = lower_bound(a, a + n, x) - a;
    auto r = upper_bound(a, a + n, x) - a;
    if (r == 0) {
        return {-1, -1};
    }
    r--;
    if (l > r) {
        return {-1, -1};
    }
    return {l, r};
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends