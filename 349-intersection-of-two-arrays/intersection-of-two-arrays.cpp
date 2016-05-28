class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> myMap;
        for (int i : nums1) {
            myMap[i] = 1;
        }
        
        set<int> ret;
        for (int i : nums2) {
            if (myMap[i] == 1)
                ret.insert(i);
        }
        
        return vector<int>(ret.begin(), ret.end());
    }
};