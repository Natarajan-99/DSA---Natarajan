#include <iostream>
#include<vector>
using namespace std;
int factorial(int k)
{
    int fact=1;
    while(k>=1)
    {
        fact=fact*k;
        k--;
    }
    return fact;
}
void Pascal_Optimized(int N)
{
    vector<vector<int>> vec; int f;
    for(int i=1;i<=N;i++)
    {
        vector<int> vec2;
        vec2.push_back(1);
        int ans=1;
        for(int j=1;j<N;j++)
        {
            ans=ans*(i-j);
            ans=ans/j;
            vec2.push_back(ans);
        }
        vec.push_back(vec2);
        vec2.clear();
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Pascal(int k)
{
    vector<int> vec;int f;
    if(k==1)
    {
        cout<<1;
    }
    if(k>=2)
    {
        cout<<1<<endl;cout<<1<<" "<<1<<endl;
    }
    int n=2,m=1;
    int i=1;
    for(int j=2;j<k;j++)
    {


    while(i<=n+1)
    {
        if(i==1)
        {
            //vec.push_back(1);
            cout<<1<<" ";
        }
        else
        {
            int l=(factorial(n))/(factorial(m)*factorial(n-m));
            //vec.push_back(l);
            m++;
            cout<<l<<" ";
        }
        i++;
    }

    n++;
    m=1;i=1;
    cout<<endl;vec.clear();
    }
}
int main()
{
    int k;
    //provide number of rows to be diplayed as input 
    cin>>k;
    Pascal(k);cout<<endl<<"Optimized code:"<<endl;
    Pascal_Optimized(k);
    return 0;
}
