#include <iostream>
#include<vector>
#include<stack>
using namespace std;
int arrsize;
struct Node
{
    int num;
    Node *next;
};
Node* root=nullptr;
stack<Node*> st;
void insertvalue(int n)
{
    Node *newnode=new Node();
    newnode->num=n;
    newnode->next=nullptr;
    if(root==nullptr)
    {
        root=newnode;
        st.push(root);
        return;
    }
    Node *temp=root;
    Node* temp1=root;
    while(temp!=nullptr)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=newnode;
    st.push(newnode);
}
/*void reverseList()
{

    Node *node=st.top();
    //cout<<node->num;
    root=node;
    root->next=nullptr;
    st.pop();
    while(!st.empty())
    {
        Node *newnode=st.top();
        Node *temp=root;
        Node *temp1=root;
        while(temp!=nullptr)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=newnode;
        newnode->next=nullptr;
        st.pop();
    }

}*/
void reversewithoutstack()
{
    Node *node=root;
    Node *t=root;
    node=node->next;
    while(node!=nullptr)
    {

        Node *tempnext=node->next;
        node->next=t;
        t=node;
        node=tempnext;
    }
    root->next=nullptr;
    root=t;
}


void print()
{
    Node *node=root;
    while(node!=nullptr)
    {
        cout<<node->num<<" ";
        node=node->next;
    }
    cout<<endl;
}
int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9,10,11};
    arrsize=arr.size();
    for(int i=0;i<arr.size();i++)
    {
        insertvalue(arr[i]);
    }
    cout<<"Actual List"<<endl;
    print();
   
    reversewithoutstack();
    cout<<"After reversing"<<endl;
    print();
    return 0;
}
