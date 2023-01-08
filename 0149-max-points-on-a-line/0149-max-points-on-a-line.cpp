class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        map<pair<int, int>, int> m;
        int ans = 0;
        int n = points.size();

        for (int i = 0; i < n; i++) {
            int curr_max = 0;
            for (int j = i + 1; j < n; j++) {
                int x = (points[i][0] - points[j][0]);
                int y = (points[i][1] - points[j][1]);

                int k = __gcd(abs(x), abs(y));
                x /= k;
                y /= k;

                if (!x) {
                    y = 1;
                }
                else if (!y) {
                    x = 1;
                }
                else if (y < 0) { // To remove negative from denominator
                    x *= -1;
                    y *= -1;
                }

                m[{x, y}]++;
                curr_max = max(curr_max, m[{x, y}]);
            }
            ans = max(ans, curr_max + 1); // +1 as 2 points altogether gives us a slope
            m.clear();
        }
        return ans;
    }
};