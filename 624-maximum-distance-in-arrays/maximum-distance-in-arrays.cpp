class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
       int mn = arrays[0][0];
        int mx = arrays[0].back();

        int ans = 0;

        for(int i = 1; i < arrays.size(); i++) {
            int currMin = arrays[i][0];
            int currMax = arrays[i].back();

            ans = max(ans, currMax - mn);
            ans = max(ans, mx - currMin);

            mn = min(mn, currMin);
            mx = max(mx, currMax);
        }

        return ans; 
    }
};