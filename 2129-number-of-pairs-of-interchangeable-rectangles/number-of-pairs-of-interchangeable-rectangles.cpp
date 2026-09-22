class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {

        unordered_map<double, long long> mp;
        long long ans = 0;

        for (auto &r : rectangles) {

            double ratio = (double)r[0] / r[1];

            // Every previous rectangle with same ratio
            // forms a pair with current rectangle
            ans += mp[ratio];

            mp[ratio]++;
        }

        return ans;
    }
};