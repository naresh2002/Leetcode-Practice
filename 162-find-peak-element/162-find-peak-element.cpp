class Solution {
public:
  int findPeakElement(vector<int>& arr) {
    int n = arr.size();
    int l = 0, r = n - 1;

    while(l < r) {
      int mid = (r + l) / 2;  

      if(arr[mid] < arr[mid + 1]) {
          l = mid + 1;
      }
      else if(arr[mid] > arr[mid + 1]) {
          r = mid;
      }
    }
    return l;
  }
};