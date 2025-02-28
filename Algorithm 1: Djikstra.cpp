#include <iostream>

using namespace std;
#define V 9
int minvalue(int dist[V],bool checker[V])
{
    int minv=INT_MAX;int minindex;
    for(int i=0;i<V;i++)
    {
        if(dist[i]<=minv && checker[i]==false)
        {
            minv=dist[i];
            minindex=i;
        }
    }
    return minindex;
}
void dijkstra(int graph[V][V],int num)
{
    int dist[V];bool checker[V];
    for(int i=0;i<V;i++)
    {

        dist[i]=INT_MAX;checker[i]=false;
    }
    dist[num]=0;
    for(int count=0;count<V-1;count++)
    {
        int u=minvalue(dist,checker);
        checker[u]=true;
        for(int v=0;v<V;v++)
        {
            if(graph[u][v]!=0 && dist[u]!=INT_MAX && checker[v]==false && (dist[u]+graph[u][v])<dist[v])
            {
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    for(int h=0;h<V;h++)
    {
        cout<<"Shortest distance of "<<num<<" "<<"from "<<h<<" is ";
        cout<<dist[h]<<endl;}
}
int main()
{
    int graph[V][V] = {
                        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 3);
    return 0;
}
