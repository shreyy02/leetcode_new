class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long comb[1001][1001];

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return 1;

        vector<int> left;
        vector<int> right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long leftWays = solve(left);
        long long rightWays = solve(right);

        long long ways = comb[left.size() + right.size()][left.size()];

        ways = ways * leftWays % MOD;
        ways = ways * rightWays % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {

        // Precompute combinations
        for (int i = 0; i <= 1000; i++) {
            comb[i][0] = comb[i][i] = 1;

            for (int j = 1; j < i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};