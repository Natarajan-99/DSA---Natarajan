// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void print(vector<vector<int>> &path,int v,int u)
{
    if(v==path[v][u])
    {
        return;
    }
    print(path,v,path[v][u]);
    cout<<path[v][u]<<", ";
}
void printsolution(vector<vector<int>> &cost, vector<vector<int>> &path)
{
    int n=cost.size();
    for(int v=0;v<n;v++)
    {
        for(int u=0;u<n;u++)
        {
            if(v!=u && path[v][u]!=-1)
            {
                cout<<"Shortest distance from "<<v<<" to "<<u<<" is "<<v<<", ";
                print(path,v,u);
                cout<<u<<endl;
            }
        }
    }
}
void FloydWarshall(vector<vector<int>> &arr)
{
    int n=arr.size();//considering arr has n*n values
    vector<vector<int>> cost(n,vector<int>(n));
    vector<vector<int>> path(n,vector<int>(n));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cost[i][j]=arr[i][j];
            if(i==j)
            {
                path[i][j]=0;
            }
            else if(cost[i][j]!=INT_MAX)
            {
                path[i][j]=i;
            }
            else
            {
                path[i][j]=-1;
            }
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(cost[i][k]!=INT_MAX && cost[k][j]!=INT_MAX && cost[i][j]>(cost[i][k]+cost[k][j]))
                {
                    cost[i][j]=cost[i][k]+cost[k][j];
                    path[i][j]=path[k][j];
                }
            }
            if(cost[i][i]<0)
            {
                cout<<"Negative weight cycle found";
                return;
            }
        }
    }
    printsolution(cost,path);
}
int main() {
    int I=INT_MAX;
    vector<vector<int>> arr =
    {
        { 0, I, -2, I },
        { 4, 0, 3, I },
        { I, I, 0, 2 },
        { I, -1, I, 0 }
    };
    FloydWarshall(arr);

    return 0;
}
