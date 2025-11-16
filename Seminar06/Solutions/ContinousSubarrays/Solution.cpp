class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        const int n=nums.size();
        long long cnt=0;
        multiset<int> hasX;
        for(int l=0, r=0; r<n; r++){
            hasX.insert(nums[r]);
            while(l<r && *prev(hasX.end())-*hasX.begin()>2){
                auto it=hasX.find(nums[l]);
                hasX.erase(it);
                l++;
            }

            // When we reach this step we have array between indecies l and r.
            // The unaccounted for arrays are {a[r]}, {a[r-1], a[r]}, {a[r-2], a[r-1], a[r]}..., {a[l],...,a[r]}
            // So we count them with r - l + 1
            // The arrays that do not contain a[r] have been accounted for on the previous step
            cnt+= r - l + 1LL; 
        }
        return cnt;
    }
};