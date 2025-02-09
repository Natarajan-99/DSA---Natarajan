#include <iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#define EMPTY_STRING ""
using namespace std;
class Node
{
public:
    int freq;
    Node* right;Node* left;
    char ch;
};
Node* getNode(int freq, char ch, Node* right,Node* left)
{
    Node *newnode=new Node();
    newnode->ch=ch;
    newnode->freq=freq;
    newnode->right=right;
    newnode->left=left;
    return newnode;
}
struct comp
{
    bool operator()(Node* l,Node* r)
    {
        return l->freq>r->freq;
    }
};
void encode(Node* root, string str,unordered_map<char,string> &huffmanencoded)
{
    if(root==nullptr)
    {
        return;
    }
    if(root->right==nullptr && root->left==nullptr)
    {
        if(str==EMPTY_STRING)
        {


        huffmanencoded[root->ch]="1";
        }
        else{
            huffmanencoded[root->ch]=str;
        }
    }
    encode(root->left,str+"0",huffmanencoded);
    encode(root->right,str+"1",huffmanencoded);
}
void decode(Node* root, int &index, string str1)
{
    if(root==nullptr)
    {
        return;
    }
    if(root->right==nullptr && root->left==nullptr)
    {
        cout<<root->ch;
        return;
    }
    index++;
    if(str1[index]=='0')
    {
        decode(root->left,index,str1);
    }
    else{
        decode(root->right,index,str1);
    }
}
void huffman(string s)
{
    unordered_map<char,int> freq;
    for(char ch:s)
    {
        freq[ch]++;
    }
    priority_queue<Node*, vector<Node*>, comp> q;
    for(auto v:freq)
    {
        q.push(getNode(v.second,v.first,nullptr,nullptr));
    }

    while(q.size()>1)
    {
        Node* first=q.top();
        //cout<<first->ch<<" ";
        q.pop();
        Node* second=q.top();
        //cout<<second->ch<<" ";
        q.pop();
        int sum=first->freq+second->freq;
        q.push(getNode(sum,'\0',first,second));
    }
    Node* root=q.top();
    unordered_map<char,string>huffmanencoded;
    encode(root,EMPTY_STRING,huffmanencoded);
    /*for(auto v:huffmanencoded)
    {
        cout<<v.first<<" "<<v.second<<" "<<endl;
    }*/
    string str1;
    for(char ch:s)
    {
        //cout<<ch<<" "<<huffmanencoded[ch]<<endl;
        str1+=huffmanencoded[ch];
    }
    cout<<"Encoded value is "<<str1<<endl;
    int index = -1;
    cout<<"On Decoding"<<" - ";
    while (index < (int)str1.size() - 1) {
            decode(root, index, str1);
    }

}
int main()
{
    string s="Missisipi";
    huffman(s);
    return 0;
}
