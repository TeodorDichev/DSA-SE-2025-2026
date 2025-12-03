class Solution {
public:
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    multiset<double>left, right;
    vector<double> res;

    for(int i = 0; i < k; i++)
    {
        if(left.size() <= right.size())
        {
            left.insert(nums[i]);
        }
        else
        {
            right.insert(nums[i]);
        }

        if(!right.empty() && *left.rbegin() > *right.begin())
        {
            int t1 = *left.rbegin();
            int t2 = *right.begin();
            left.erase(--left.end());
            right.erase(right.begin());

            right.insert(t1);
            left.insert(t2);
        }
    }

    for(int i = k; i <= n; i++)
    {
        if (left.size() == right.size()) {
            double x = *left.rbegin() + *right.begin();
            res.push_back((double)x / (2 * 1.0));
        }
        else
            res.push_back((double)*left.rbegin());

        if((*left.rbegin()) >= nums[i - k])
            left.erase(left.find(nums[i - k]));
        else
            right.erase(right.find(nums[i - k]));

        if(i == n)
            break;

        if(left.size() <= right.size())
        {
            left.insert(nums[i]);
        }
        else
        {
            right.insert(nums[i]);
        }

        if(!right.empty() && *left.rbegin() > *right.begin())
        {
            int t1 = *left.rbegin();
            int t2 = *right.begin();
            left.erase(--left.end());
            right.erase(right.begin());

            right.insert(t1);
            left.insert(t2);
        }
    }
    
    return res;
}
};