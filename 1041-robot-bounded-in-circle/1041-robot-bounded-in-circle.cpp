class Solution {
public:
  bool isRobotBounded(string s) {
    pair<int, int> p[4];
    p[0] = {0, 1};
    p[1] = {-1, 0};
    p[2] = {0, -1};
    p[3] = {1, 0};
    
    int curr_x = 0, curr_y = 0;
    int n = s.size();
    int k = 0;
    
    for (int j = 0; j < 4 * n; j++) {
      int i = j % n;
      if (s[i] == 'L') {
        k = ((k + 1) % 4);
      }
      else if (s[i] == 'R') {
        k = ((k + 3) % 4);        
      }
      else {
        // cout << curr_x << " " << curr_y << endl;
        curr_x += p[k].first;
        curr_y += p[k].second;
      }
    }
    if (curr_x == 0 && curr_y == 0) {
      return true;
    }
    return false;
  }
};