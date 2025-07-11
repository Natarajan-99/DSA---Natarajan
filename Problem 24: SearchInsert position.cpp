class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i,j,n=nums.size();
        i=0;
        while(i<n)
        {
            if(target==nums[i])
            {
                break;
                return i+1;
            }
            else if(target<nums[i])
            {
                break;
                return i+1;
            }
            i++;
        }
        return i;
    }
    
};
