class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0 , j = numbers.size() - 1;
    while(j > i) {
      int res = numbers[i] + numbers[j];
      if(res  > target) {
        j--;
      }
      else if (res < target) {
        i++;
      }
      else {
        return {++i,++j};
      }
    }
    return {};
  }
};