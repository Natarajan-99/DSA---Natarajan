#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> mergearr(vector<vector<int>> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(auto i:arr)
    {
        if(ans.empty())
        {
            ans.push_back(i);
        }
        else if(ans.back()[1]<i[0])
        {
            ans.push_back(i);
        }
        else if(i[1]>ans.back()[1])
        {
            ans.back()[1]=i[1];
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> arr={{1,3},{2,6},{8,10},{15,18},{5,7}};
    vector<vector<int>> ans=mergearr(arr);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
