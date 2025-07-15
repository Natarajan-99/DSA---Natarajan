#include <iostream>
#include<vector>
#include<climits>

using namespace std;
struct Edge{
    int source,dest,weight;
};
void printPath(vector<int> &parent,int vertex,int source)
{
    if(vertex<0)
    {

        return;
    }
    printPath(parent,parent[vertex],source);
    if(vertex!=source)
    {
        cout<<", ";
    }
    cout<<vertex;
}
void BellmanFord(vector<Edge> &edges,int source,int n)
{
    vector<int> distance(n,INT_MAX);
    distance[source]=0;
    vector<int> parent(n,-1);
    int u,v,weight,i;
    int k=n;
    while(k--)
    {
        for(Edge edge: edges)
        {
            u=edge.source;
            v=edge.dest;
            weight=edge.weight;
            if(distance[u]!=INT_MAX && (distance[u]+weight)<distance[v])
            {
                distance[v]=distance[u]+weight;
                parent[v]=u;
            }
        }
    }
    for(Edge edge: edges)
    {
         u=edge.source;
         v=edge.dest;
         weight=edge.weight;
         if(distance[u]!=INT_MAX && distance[u]+weight<distance[v])
         {

             cout<<"Negative weight cycle found";
             return;
         }
    }
    for(i=0;i<n;i++)
    {
        if(i!=source && distance[i]!=INT_MAX)
        {

           //cout << "The distance of vertex " << i << " from the source is "<< " " << distance[i] << ". Its path is [";
             //   printPath(parent, i, source); cout << "]" << endl;
             cout << "The distance of vertex " << i << " from the source "<<source<< " is "<< " " << distance[i] << ". Its path is [";
                printPath(parent, i, source); cout << "]" << endl;
           //cout<<i<<" "<<distance[i]<<endl;
        }
    }
    /*for(i=0;i<n;i++)
    {

        cout<<parent[i]<<" ";
    }*/

}
int main()
{
     vector<Edge> edges =
        {
            // (x, y, w) —> edge from x to y having weight w
            {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
            {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
        };
        int n=5;
        for(int source=0;source<n;source++)
        {

            BellmanFord(edges,source,n);
        }
    return 0;
}
