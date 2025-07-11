class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
    vector<int> uniquevalues;
    unordered_map<int,int> countnum;
    for(int i=0;i<n;i++)
    {
        int k=nums[i];
        countnum[k]++;
        if(countnum[k]==1)
        {
            uniquevalues.push_back(k);
        }
    }
    int length=uniquevalues.size(),check=n/2;
    //bool flag=false;
    for(int i=0;i<length;i++)
    {
        int k=uniquevalues[i];
        if(countnum[k]>check)
        {
            return k;
            //flag=true;
        }
    }
    return uniquevalues[0];
    }
};
