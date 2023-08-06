class Solution {
public:
    // https://leetcode.com/problems/number-of-music-playlists/discuss/180338/DP-solution-that-is-Easy-to-understand
    int numMusicPlaylists(int n, int goal, int k) {
        int MOD = 1000000007;
        vector<vector<long long>> dp(goal + 1, vector<long long> (n + 1, 0LL));
        // dp[i][j] denotes the solution of i songs with j different songs
        dp[0][0] = 1LL;
        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= n; j++) {
                // CASE 1 (the last added one is new song) : Listen i - 1 songs with j - 1 different songs, then the last one is definitely new song with the choices of n - (j - 1).
                dp[i][j] = (dp[i - 1][j - 1] * (n - (j - 1))) % MOD;
                
                // Case 2 (the last added one is old song): 
                if (j > k) {
                    dp[i][j] = (dp[i][j] + (dp[i - 1][j] * (j - k)) % MOD) % MOD;
                }
            }
        }
        return (int)dp[goal][n];
    }
};