class Solution {
public:
    string frequencySort(string s) {
    map<char,int> freq;
    int n=s.length();
    for(int i=0;i<n;i++)
    {
        freq[s[i]]++;
    }
    string solution="";
   
    priority_queue<pair<int,char>>pq;
    for(auto i:freq)
    {
        pq.push({i.second,i.first});
    }
    while(!pq.empty())
    {
        pair<int,char> temp=pq.top();
        int loop=temp.first;
        while(loop--)
        {
            solution+=temp.second;
        }
        //cout<<temp.first<<" "<<temp.second<<endl;
        pq.pop();
    }

    return solution;
    }
};
