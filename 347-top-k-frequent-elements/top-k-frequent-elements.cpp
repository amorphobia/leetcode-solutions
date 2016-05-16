class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> appearance;
        for (int n : nums) {
            ++appearance[n];
        }
        vector<pair<int, int>> stats;
        for (auto p : appearance) {
            stats.push_back(p);
        }

        sort(stats.begin(), stats.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second >= b.second;
        });

        vector<int> ret;
        for (uint i = 0; i < k; ++i) {
            ret.push_back(stats[i].first);
        }

        return ret;
    }
};
