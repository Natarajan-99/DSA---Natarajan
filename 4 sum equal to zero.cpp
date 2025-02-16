#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> foursum(vector<int> &arr)
{
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<vector<int>> result;
    for(int i=0;i<n;i++)
    {
        if(i!=0 && arr[i]==arr[i-1])
        {
            continue;
        }
        for(int j=i+1;j<n;j++)
        {
            if(j>i+1 && arr[j]==arr[j-1])
            {
                continue;
            }
            int h=j+1,k=n-1;
            while(h<k)
            {
                int sum=arr[i]+arr[j]+arr[h]+arr[k];
                if(sum<0)
                {
                    h++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    vector<int> temp={arr[i],arr[j],arr[h],arr[k]};
                    result.push_back(temp);
                    h++;k--;
                    while(h>j+1 && arr[h]==arr[h+1])h++;
                    while(k<n-1 && arr[k]==arr[k-1])k--;
                }
            }
        }
    }
    return result;
}
int main()
{
    vector<int> arr={-3,-2,-1,0,1,2,3,4,5,0,0,8,-4};
    vector<vector<int>> result=foursum(arr);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[0].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
