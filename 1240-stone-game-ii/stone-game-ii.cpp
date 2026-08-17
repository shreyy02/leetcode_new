class Solution {
public:
    int solve(vector<int>& suffix, vector<vector<int>>& dp,
              int i, int M, int n) {

        if (i >= n)
            return 0;

        if (dp[i][M] != -1)
            return dp[i][M];

        int ans = 0;

        for (int X = 1; X <= 2 * M && i + X <= n; X++) {

            int nextM = max(M, X);

            int opponent = solve(suffix, dp, i + X, nextM, n);

            int current = suffix[i] - opponent;

            ans = max(ans, current);
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        // suffix[i] = sum of piles from i to n-1
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(suffix, dp, 0, 1, n);
    }
};