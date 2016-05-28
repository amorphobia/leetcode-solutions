class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> myMap;
        for (int i : nums1) {
            ++myMap[i];
        }
        
        vector<int> ret;
        for (int i : nums2) {
            if (myMap[i]) {
                ret.push_back(i);
                --myMap[i];
            }
        }
        
        return ret;
    }
};