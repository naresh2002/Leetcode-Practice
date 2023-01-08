class Solution {
public:
    int numTrees(int n) {
        int dp[20] = {0};
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += (dp[j] * dp[i - j - 1]);
            }
        }
        return dp[n];
    }

/*
Approach (CATALAN Number):
We can find the number of BST’s by thinking in recursive manner for ease:

1. Choose 1 as root, no element present on left-subtree. N-1 elements present on the right subtree.

2. Choose 2 as root, 1 element present on the left-subtree. N-2 elements present on the right-subtree.

3. Similarly, Choose i as root, i-1 elements present on the left-subtree. N-i elements on the right-subtree.

Then, Total number of BST’s C(N) = C(0)C(N-1) + C(1)C(N-2) +………+ C(i-1)C(N-i) +………….+ C(N-1)C(0).
where C(i) is the number of unique BST with i nodes.
*/
};