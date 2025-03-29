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
        root=root->next;
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
};
