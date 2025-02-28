#include <iostream>

using namespace std;
//This algorithm will return the corrupted node among n number of nodes

struct Node
{

    Node *next;
    int data;
};


void create(Node* node,int k)
{
    if(node==NULL)
    {
       node->next=NULL;
       node->data=k;
    }
    else
    {
        Node* temp=node;
        Node* prev=node;
        while(temp!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        Node* node1=new Node();
        node1->data=k;node1->next=NULL;
        prev->next=node1;
    }
}
void display(Node* node)
{
    Node* temp=node;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void corrupt(Node* node)
{
    Node* temp=node;
    Node* prev=node;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        prev=temp;
        //cout<<temp->data<<" ";
        temp=temp->next;
        if(i==3)
        {
            break;
        }
    }cout<<endl;
    prev->next=node;


}
int findloop(Node* head)
{
    Node* slow=head;
    Node* fast=head;
    int counter=0;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        counter++;
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            cout<<"The affected node is "<<counter;
            return 1;
        }
    }
    return 0;
}
int main()
{
    Node* head=new Node();
    head->data=10;
    head->next=NULL;
    create(head,20);
    create(head,30);
    create(head,40);
    create(head,50);
    create(head,60);
    create(head,70);
    create(head,80);display(head);
    corrupt(head);

    int k=findloop(head);
    return 0;
}
