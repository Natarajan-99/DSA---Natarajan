#include <iostream>

using namespace std;
class Node
{
    public:
    Node *right;
    Node *left;int key;int height;
};
Node* NewNode(int n)
{
    Node* node=new Node();
    node->right=nullptr;
    node->left=nullptr;
    node->key=n;
    node->height=1;
}
int height(Node* node)
{
    if(node==nullptr)
    {
        return 0;
    }
    return node->height;
}
int BalanceCheck(Node *node)
{
    if(node==nullptr)
    {
        return 0;
    }
    return height(node->left)-height(node->right);
}
Node *rightRotation(Node* x)
{
    Node* y=x->left;
    Node*z=y->right;
    y->right=x;
    x->left=z;
    x->height=1+max(height(x->left),height(x->right));
    y->height=1+max(height(y->left),height(y->right));
    return y;
}
Node *leftRotation(Node *x)
{
    Node* y=x->right;
    Node* z=y->left;
    y->left=x;
    x->right=z;
    x->height=1+max(height(x->left),height(x->right));
    y->height=1+max(height(y->left),height(y->right));
    return y;
}
Node* insert(Node *node,int key)
{
    if(node==nullptr)
    {
        return NewNode(key);
    }
    if(key<node->key)
    {
        node->left=insert(node->left,key);
    }
    else if(key>node->key)
    {
        node->right=insert(node->right,key);
    }
    else{
        return node;
    }
    node->height=1+max(height(node->left),height(node->right));
    int bal=BalanceCheck(node);
    if(bal>1 && key<node->left->key)
    {
        return rightRotation(node);
    }
    if(bal<-1 && key>node->right->key)
    {

        return leftRotation(node);
    }
    if(bal>1 && key>node->left->key)
    {
        node->left=leftRotation(node->left);
        return rightRotation(node);
    }
    if(bal<-1 && key<node->right->key)
    {
        node->right=rightRotation(node->right);
        return leftRotation(node);
    }
    return node;

}
void PreOrder(Node *node)
{
    if(node!=nullptr)
    {
        cout<<node->key<<" ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
}
void PostOrder(Node *node)
{
    if(node!=nullptr)
    {
        PostOrder(node->left);
        PostOrder(node->right);
        cout<<node->key<<" ";
    }
}
void InOrder(Node* node)
{
    if(node!=nullptr)
    {
        InOrder(node->left);
        cout<<node->key<<" ";
        InOrder(node->right);

    }
}
int main()
{
    int arr[5]={6,7,8,9,10};
    Node* root=nullptr;
    for(int i=0;i<5;i++)
    {
        root=insert(root,arr[i]);

    }
    cout<<"PreOrder display"<<endl;
    PreOrder(root);
    cout<<endl;
    cout<<"PostOrder display"<<endl;
    PostOrder(root);
    cout<<endl;
    cout<<"InOrder display"<<endl;
    InOrder(root);
    return 0;
}
