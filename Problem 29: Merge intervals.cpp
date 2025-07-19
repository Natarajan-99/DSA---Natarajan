class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> vec;
        for(auto i:intervals)
        {
            if(vec.empty())
            {
                vec.push_back(i);
            }
            else if(vec.back()[1]<i[0])
            {
                vec.push_back(i);
            }
            else if(i[1]>vec.back()[1])
            {
                vec.back()[1]=i[1];
            }
        }
        return vec;
    }
};
