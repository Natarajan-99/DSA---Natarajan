
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void find(vector<int> &arr)
{
    int l=arr.size();
    for(int i=0;i<l;i++)
    {
        for(int j=i+1;j<l;j++)
        {
            for(int k=j+1;k<l;k++)
            {
                if(arr[i]+arr[j]+arr[k]==0)
                {
                    cout<<"index "<<i<<" "<<j<<" "<<k<<"; numbers are "<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                }
            }
        }
    }
}
vector<vector<int>> triplet(vector<int> &arr)
{
    vector<vector<int>> ans;
    int n=arr.size();
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        int j=i+1,k=n-1;
        if(i!=0 && arr[i]==arr[i-1])continue;

            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    vector<int> temp_vec={arr[i],arr[j],arr[k]};
                    ans.push_back(temp_vec);
                    j++;k--;
                    while(j<k && arr[j]==arr[j-1])j++;
                    while(j<k && arr[k]==arr[k+1])k--;
                }
            }

    }
    return ans;
}
int main()
{
    vector<int> vec={-2, -2,-2,-1,-1,-1,0,0,0,2,2,2,2,2};
    vector<vector<int>> ans=triplet(vec);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
