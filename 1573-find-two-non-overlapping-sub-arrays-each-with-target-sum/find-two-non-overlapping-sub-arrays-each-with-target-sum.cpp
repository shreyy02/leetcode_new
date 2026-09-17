class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        vector<int> dp(n, INF);
        unordered_map<int, int> mp;

        int sum = 0;
        int ans = INF;

        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += arr[i];

            // If a previous subarray with target sum exists
            if (mp.count(sum - target)) {
                int start = mp[sum - target] + 1;
                int len = i - start + 1;

                // Need a non-overlapping subarray before this one
                if (start > 0 && dp[start - 1] != INF) {
                    ans = min(ans, len + dp[start - 1]);
                }

                // Store the minimum length subarray ending at i
                if (i == 0)
                    dp[i] = len;
                else
                    dp[i] = min(dp[i - 1], len);
            }
            else {
                if (i > 0)
                    dp[i] = dp[i - 1];
            }

            // Store latest index for prefix sum
            mp[sum] = i;
        }

        return ans == INF ? -1 : ans;
    }
};