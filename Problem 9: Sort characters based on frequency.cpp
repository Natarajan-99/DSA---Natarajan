#include <iostream>
#include<map>
#include<queue>
#include <bits/stdc++.h>
using namespace std;
string SoringCharacters(string s)
{
    map<char,int> freq;
    int n=s.length();
    priority_queue<pair<int,char>>pq;
    for(int i=0;i<n;i++)
    {
        char ch=s[i];
        if(freq.count(ch)>0)
        {
            freq[ch]++;
        }
        else
        {
            freq.insert({ch,1});
            //pq.push({1,ch});
        }

    }
    string solution="";
    pair<int,char> p;
    for(auto i:freq)
    {
        char c=i.first;int f=i.second;
        p={f,c};
        pq.push(p);
    }
    while(!pq.empty())
    {
        pair<int,char> temp=pq.top();
        int loop=temp.first;
        while(loop--)
        {
            solution+=temp.second;
        }
        pq.pop();
    }
    return solution;


}
int main()
{

    string s="cccaaa";
    string str=SoringCharacters(s);
    cout<<str;
    return 0;
}
