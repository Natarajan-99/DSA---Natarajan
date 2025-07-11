#include <iostream>
#include<string>
#include <map>
using namespace std;
struct Node
{
    string s;
    Node* next;
    Node* down;
};
Node* root=nullptr;
Node *clonedroot=nullptr;
Node* NewNode(string s)
{
    Node* newnode=new Node();
    newnode->s=s;
    newnode->next=nullptr;
    newnode->down=nullptr;
    return newnode;
}
void create(string s)
{
    if(root==nullptr)
    {
        root=NewNode(s);
        return;
    }
    Node* temproot=root;
    Node* temp=root;
    while(temproot!=nullptr)
    {
        string str1=temproot->s;
        int ch1=str1[0];int ch2=s[0];
        if(ch1<97)
        {
            ch1+=32;
        }
        if(ch2<97)
        {
            ch2+=32;
        }
        if(ch2<ch1)
        {
            //cout<<s;
            Node* tempn=NewNode(s);
            Node* tempn1=temproot;
            temproot=tempn;temp->next=temproot;
            temproot->next=tempn1;
            return;

        }
        else if(ch2==ch1)
        {
            Node* tempn=NewNode(s);
            //Node*y=temproot;
            while(temproot->down!=nullptr)
            {
                temproot=temproot->down;
            }
            temproot->down=tempn;
            return;
        }
        /*else
        {
            Node* tempn=NewNode(s);
            temproot->next=tempn;
        }*/
        temp=temproot;
        temproot=temproot->next;
    }
    Node* tempn=NewNode(s);
    temp->next=tempn;
}
/*void CreateNew(string s)
{
    if(root==nullptr)
    {
        root=NewNode(s);
        return;
    }
    Node* temproot=root;
    Node* t=root;
    while(temproot!=nullptr)
    {

    }
}*/
void Add(string s)
{
    Node *newnode=NewNode(s);
    char ch=s[0];
    Node *temproot=root;
    ch=toupper(ch);
    while(temproot!=nullptr)
    {
        char ch1=temproot->s[0];
        ch1=toupper(ch1);
        if(ch==ch1)
        {
            while(temproot->down!=nullptr)
            {
                temproot=temproot->down;
            }
            temproot->down=newnode;
            return;
            //break;
        }
        temproot=temproot->next;
    }
}
void DisplayAlphabets()
{
    Node* temp=root;
    while(temp!=nullptr)
    {
        char c=temp->s[0];
        c=toupper(c);
        cout<<c<<endl;
        temp=temp->next;
    }
}
void CloningLinkedList()
{
    Node* node=root;
    string ch=root->s;
    clonedroot=NewNode(ch);
    Node* nodecloned=clonedroot;
    while(node!=nullptr)
    {
        Node* tempnode=node;
        if(node!=root)
        {
            string s=node->s;
            Node* n=NewNode(s);
            nodecloned->next=n;
            nodecloned=nodecloned->next;
        }
        Node* clonedtempnode=nodecloned;
        while(tempnode->down!=nullptr)
        {
            tempnode=tempnode->down;
            string s=tempnode->s;

            Node* newnode=NewNode(s);
            clonedtempnode->down=newnode;
            clonedtempnode=clonedtempnode->down;
        }

        node=node->next;
        //nodecloned=nodecloned->next;
    }


    //Extra
    /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
class Solution {
public:
    Node* copyRandomList(Node* root) {
    if(root==NULL)
    {
        return root;
    }
    Node* node=root;
    int ch=root->val;
    Node* clonedroot=new Node(ch);
    Node* nodecloned=clonedroot;
    root=root->next;
    while(root!=NULL)
    {
        clonedroot->next=new Node(root->val);
        /*if(root->random!=NULL)
        {
            clonedroot->random=root->random;
        }*/
        /*root=root->next;
        clonedroot=clonedroot->next;
    }
    clonedroot=nodecloned;
    unordered_map<Node*,Node*>mp;
    root=node;
    while(root!=NULL)
    {
        mp[root]=clonedroot;
        root=root->next;
        clonedroot=clonedroot->next;
    }
    for(auto &it:mp)
    {
        if(it.first->random!=NULL)
        {
            it.second->random=mp[it.first->random];
        }
    }

    return nodecloned;
    }
};*/


}
void DisplaybasedonChar(char ch)
{
     Node* temp=root;
    while(temp!=nullptr)
    {
        if(toupper(ch)==toupper(temp->s[0])){
        cout<<temp->s<<endl;;
        Node* tempn=temp;
        while(tempn->down!=nullptr)
        {
            Node* t=tempn->down;
            cout<<t->s<<endl;
            tempn=tempn->down;
        }
        }
        temp=temp->next;
    }

}
void Display()
{
    Node* temp=root;
    while(temp!=nullptr)
    {
        cout<<temp->s<<endl;
        Node* tempn=temp;
        while(tempn->down!=nullptr)
        {
            Node* t=tempn->down;
            cout<<t->s<<endl;
            tempn=tempn->down;
        }
        //cout<<endl;
        temp=temp->next;
    }
}
void DisplayOriginal()
{
    Node* temp=root;
    while(temp!=nullptr)
    {
        cout<<temp->s<<endl;
        Node* tempn=temp;
        while(tempn->down!=nullptr)
        {
            Node* t=tempn->down;
            cout<<t->s<<endl;
            tempn=tempn->down;
        }
        //cout<<endl;
        temp=temp->next;
    }
}
void DisplayClonedNode()
{
    Node* temp=clonedroot;
    while(temp!=nullptr)
    {
        cout<<temp->s<<endl;
        Node* tempn=temp;
        while(tempn->down!=nullptr)
        {
            Node* t=tempn->down;
            cout<<t->s<<endl;
            tempn=tempn->down;
        }
        //cout<<endl;
        temp=temp->next;
    }
}
int main()
{
    string str[13]={"A","Fox","is","after","another","fox","Hello","Below","Ball","Horse","Hall","Horror","Dell"};
    map<char,int> freq;

    for(int i=0;i<13;i++)
    {
        char ch=str[i][0];
        ch=toupper(ch);
        if((freq.find(ch) != freq.end()))
        {
            //cout<<str[i]<<endl;
            freq[ch]++;
            Add(str[i]);
        }
        else
        {
            create(str[i]);
            freq.insert({ch,1});
        }
        //create(str[i]);

    }
    //DisplayAlphabets();
    //cout<<"Choose the alphabet"<<endl;
    //char ch;
    //cin>>ch;
    //DisplaybasedonChar(ch);
    //cout<<"Displaying Original List"<<endl;
    //DisplayOriginal();
    CloningLinkedList();
    cout<<"Displaying Cloned List"<<endl;;
    DisplayClonedNode();
    //Display();
    return 0;
}
