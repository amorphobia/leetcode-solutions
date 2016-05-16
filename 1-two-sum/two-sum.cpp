class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); ++i) {
            int cand = target - nums[i];
            if (hash_map[cand] != 0) {
                vector<int> ret {hash_map[cand] - 1, i};
                return ret;
            }
            hash_map[nums[i]] = i + 1;
        }
        
        return vector<int>();
    }
};