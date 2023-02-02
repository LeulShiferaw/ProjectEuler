#include <bits/stdc++.h>

using namespace std;

int searchRangeStart(vector<int> &nums, int s, int e, int t)
    {
        if(s == e-1)
        {
            if(nums[s] == t)
            {
                if(s != 0)
                {
                    if(nums[s-1] < t)
                        return s;
                    else return -1;
                }
                else return s;
            }
            return -1;
        }
        
        int m = (s+e)/2;
        if(m == 0)
        {
            if(nums[m] == t)
                return m;
        }
        
        if(nums[m] == t)
        {
            if(nums[m-1] < t)
                return t;
            else return searchRangeStart(nums, s, m, t);
        }
        else if(nums[m] < t)
            return searchRangeStart(nums, m, e, t);
        return searchRangeStart(nums, s, m, t);
    }
    
    int searchRangeEnd(vector<int> &nums, int s, int e, int t)
    {
        
        if(s == e-1)
        {
            if(nums[s] == t)
            {
                if(s != nums.size()-1)
                {
                    if(nums[s+1] > t)
                        return s;
                    else return -1;
                }
                else return s;
            }
            return -1;
        }
        
        int m = (s+e)/2;
        if(m == nums.size()-1)
        {
            if(nums[m] == t)
                return m;
        }
        
        if(nums[m] == t)
        {
            if(nums[m+1] > t)
                return t;
            else return searchRangeEnd(nums, m, e, t);
        }
        else if(nums[m] > t)
            return searchRangeEnd(nums, s, m, t);
        return searchRangeEnd(nums, m, e, t);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int i = searchRangeStart(nums, 0, nums.size(), target);
        res.push_back(i);
        if(i == -1)
        {
            res.push_back(-1);
            return res;
        }
        int j = searchRangeEnd(nums, 0, nums.size(), target);
        res.push_back(j);
        return res;
    }

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    auto res = searchRange(nums, 8);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}