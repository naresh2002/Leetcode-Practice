class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int leftMax = height[0];
        vector<int> leftMaxHeight (n, 0);
        for (int i = 1; i < n; i++) {
            leftMaxHeight[i] = max(leftMaxHeight[i - 1], leftMax);
            leftMax = max(leftMax, height[i]);
        }
        
        int rightMax = height[n - 1];
        vector<int>rightMaxHeight (n, 0);
        for (int i = n - 2; i >= 0; i--) {
            rightMaxHeight[i] = max(rightMaxHeight[i + 1], rightMax);
            rightMax = max(rightMax, height[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int k = min(leftMaxHeight[i], rightMaxHeight[i]);
            ans += max(0, k - height[i]);
        }
        
        return ans;
    }
};