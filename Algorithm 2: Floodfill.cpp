#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isSafe(vector<vector<char>>& mat,int i,int j, char ch)
{
    return(i<mat.size() && j<mat[0].size() && mat[i][j]==ch && i>=0 && j>=0);
}
void printmatrix(vector<vector<char>>& mat)
{

    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Floodfill(vector<vector<char>>& mat, pair<int,int>& src, char replacement)
{
    int i;
    int row[8]={-1,-1,-1,0,0,1,1,1};
    int col[8]={-1,0,1,-1,1,-1,0,1};
    char ch=mat[src.first][src.second];
    if(ch==replacement)
    {

        return;
    }
    queue<pair<int,int>> q;
    q.push(src);
    while(q.size()>0)
    {
        pair<int,int> p1=q.front();
        q.pop();
        for(i=0;i<8;i++)
        {
                if(isSafe(mat,p1.first+row[i],p1.second+col[i],ch))
                {
                    pair<int,int>temp={p1.first+row[i],p1.second+col[i]};
                    q.push(temp);
                    mat[p1.first+row[i]][p1.second+col[i]]=replacement;
                }
        }

    }
}
int main()
{
    vector<vector<char>> mat =
    {
        { 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G' },
        { 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'Y', 'Y', 'Y' },
        { 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'Y', 'X', 'X' },
        { 'W', 'W', 'W', 'W', 'W', 'G', 'G', 'G', 'X', 'X' },
        { 'W', 'R', 'R', 'R', 'R', 'R', 'G', 'Y', 'X', 'Y' },
        { 'W', 'W', 'W', 'R', 'R', 'G', 'G', 'X', 'X', 'Y' },
        { 'W', 'B', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'X' },
        { 'W', 'B', 'B', 'B', 'B', 'R', 'R', 'X', 'X', 'X' },
        { 'W', 'B', 'B', 'X', 'B', 'B', 'B', 'B', 'X', 'X' },
        { 'W', 'B', 'B', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
    };
    pair<int,int> src={3,9};
    char replacement='Z';
    cout<<"Before replacement"<<endl;
    printmatrix(mat);
    Floodfill(mat,src,replacement);
    cout<<"After replacement"<<endl;
    printmatrix(mat);
    return 0;
}
