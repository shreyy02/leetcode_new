class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, pair<int, int>>> events;

        for (auto &b : buildings) {
            int l = b[0];
            int r = b[1];
            int h = b[2];

            // start event
            events.push_back({l, {-h, r}});

            // end event
            events.push_back({r, {0, 0}});
        }

        sort(events.begin(), events.end());

        priority_queue<pair<int, int>> pq;
        pq.push({0, INT_MAX});

        vector<vector<int>> ans;
        int prevHeight = 0;

        for (auto &event : events) {
            int x = event.first;
            int h = event.second.first;
            int r = event.second.second;

            if (h < 0) {
                // Building starts
                pq.push({-h, r});
            }

            // Remove buildings which have ended
            while (!pq.empty() && pq.top().second <= x) {
                pq.pop();
            }

            int currHeight = pq.top().first;

            if (currHeight != prevHeight) {
                ans.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return ans;
    }
};