class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        unordered_map<int, int> mp;
        for (int i = 0; i <= num; ++i) {
            ret.push_back(countBitsSingle(i, mp));
        }
        return ret;
    }

    int countBitsSingle(int n, unordered_map<int, int> &mp) {
        if (n == 0) return 0;

        if (mp[n] == 0) {
            mp[n] = 1 + mp[n - (int)pow(2, (int)log2(n))];
        }

        return mp[n];
    }
};