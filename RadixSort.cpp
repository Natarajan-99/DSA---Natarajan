#include <iostream>
#include <vector>
#include<chrono>
#include<algorithm>
using namespace std;
using namespace std::chrono;
void Radixsort(vector<int>& arr)
{
    vector<int> arr1;
    vector<vector<int>> value;
    value.resize(10);
    int max_v=-1;
    for(int i=0;i<arr.size();i++)
    {
        arr1.push_back(arr[i]);
        if(max_v<arr[i])
        {
            max_v=arr[i];
        }
    }
    int count=0;
    while(max_v>0)
    {
        max_v=max_v/10;
        count++;
    }
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<arr1.size();j++)
        {
            int t=i,k=arr1[j];
            while(t>0)
            {
                k=k/10;t--;
            }
            k=k%10;

            value[k].push_back(arr1[j]);
        }

        int i1=0;
        for(int j=0;j<=9;j++)
        {
            for(int k=0;k<value[j].size();k++)
            {
                arr1[i1++]=value[j][k];//cout<<value[j][k]<<" ";
            }
        }
        //cout<<"i "<<i<<endl;
        /*for(int i2=0;i2<arr1.size();i2++)
        {
            //cout<<arr1[i2]<<" ";
        }
        //cout<<endl;*/
        value.clear();
        value.resize(10);
    }for(int i2=0;i2<arr1.size();i2++)
        {
            cout<<arr1[i2]<<" ";
        }
        cout<<endl;//cout<<endl;

}
int main()
{
    vector<int> arr;//={1,982,800,3,57,10,60,170};
    for(int i=0;i<10000;i++)
    {
        int k=rand();
        arr.push_back(k);
    }cout<<"Before sorting "<<endl;
    for(int i=0;i<1000;i++)
    {
        cout<<arr[i]<<" ";
    }
    auto start=high_resolution_clock::now();cout<<endl;
    cout<<"After sorting "<<endl;
    Radixsort(arr);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    unsigned long d=duration.count();

    cout << "Time taken by function: "<< d << " microseconds" << endl;
    cout << "Time taken by function: "<< d/1000000 << " seconds " << endl;
    return 0;
}
