class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> vec;
        vec.push_back(nums[0]);
        int minval=nums[0];
        bool flag=false;
        for(int i=1;i<nums.size();i++)
        {
            if(!flag)
            {
            //int val=nums[i]-nums[i+1];
                if(nums[i]>=nums[i-1])
                {
                    vec.push_back(nums[i]);
                    if(nums[i]<minval)
                    {
                        minval=nums[i];
                    }
                }
                else
                {
                    flag=true;
                    if(nums[i]>minval)
                    {
                        return false;
                    }
                }
            }
            else
            {
                if(nums[i]>minval || nums[i]<nums[i-1])
                {
                    return false;
                }
            }
        }
        return true;
            

    }
};
