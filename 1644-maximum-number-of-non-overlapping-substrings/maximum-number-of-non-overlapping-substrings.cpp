class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < s.size(); i++) {
            int x = s[i] - 'a';

            if (first[x] == -1)
                first[x] = i;

            last[x] = i;
        }

        vector<pair<int, int>> intervals;

        // Find valid intervals
        for (int c = 0; c < 26; c++) {

            if (first[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            for (int i = l; i <= r; i++) {

                int x = s[i] - 'a';

                // Character appears before l
                if (first[x] < l) {
                    valid = false;
                    break;
                }

                // Need to expand interval
                r = max(r, last[x]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a.second < b.second;
             });

        vector<string> ans;
        int prevEnd = -1;

        for (auto &p : intervals) {

            int l = p.first;
            int r = p.second;

            if (l > prevEnd) {
                ans.push_back(s.substr(l, r - l + 1));
                prevEnd = r;
            }
        }

        return ans;
    }
};