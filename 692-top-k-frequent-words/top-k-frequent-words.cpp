class Solution {
public:

    struct cmp {
        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) {

            if (a.first != b.first)
                return a.first > b.first;

            return a.second < b.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            cmp
        > pq;

        unordered_map<string, int> f;

        for (string word : words)
            f[word]++;

        for (auto i : f) {

            string word = i.first;
            int frequency = i.second;

            pair<int, string> curr = {frequency, word};

            if (pq.size() < k) {
                pq.push(curr);
            }
            else if (curr.first > pq.top().first) {
                pq.pop();
                pq.push(curr);
            }
            else if (curr.first == pq.top().first &&
                     curr.second < pq.top().second) {
                pq.pop();
                pq.push(curr);
            }
        }

        vector<string> res;

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};