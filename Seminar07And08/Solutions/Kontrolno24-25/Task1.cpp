
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> counter;
        for(auto n: nums1) {
            counter[n]++;
        }
        
        vector<int> result;
        for(auto n: nums2) {
            if(counter[n] > 0) {
                counter[n]--;
                result.push_back(n);
            }
        }
        
        return result;
    }
};