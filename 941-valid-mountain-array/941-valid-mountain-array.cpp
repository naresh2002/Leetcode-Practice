class Solution {
public:
  bool validMountainArray(vector<int>& arr) {
    int k = 1;
    int pos = -1;
    for (int i = 1; i < (int)arr.size(); i++) {
      if (arr[i] < arr[i - 1]) {
        pos = i;
        break;
      }
    }
    if (pos == -1 || arr[0] >= arr[1]) {
      return false;
    }
    for (int i = 1; i < pos; i++) {
      if (arr[i] <= arr[i - 1]) {
        return false;
      }
    }
    for (int i = pos + 1; i < (int)arr.size(); i++) {
      if (arr[i] >= arr[i - 1]) {
        return false;
      }
    }
    return true;
  }
};