/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* root, int n) {
    int arrsize=0;
    ListNode dummy(0);
    dummy.next=root;
    ListNode* tn=root;
    ListNode* temp=&dummy;
    while(tn!=nullptr)
    {
        arrsize++;
        tn=tn->next;
    }
    while(arrsize>=n)
    {
        tn=temp->next;
        ListNode* next=tn->next;
        for(int i=0;i<n-1;i++)
        {
            tn->next=next->next;
            next->next=temp->next;
            temp->next=next;
            next=tn->next;
        }
        temp=tn;
        arrsize-=n;
    }
    root=dummy.next;
    return root;
    
    /*ListNode *node=root;
    ListNode *t=root;
    ListNode* mark=root;
    node=node->next;
    ListNode* tempnext=root;
    bool flag=false;
    int count=1;
    int tv=1;
    ListNode* temproot=root;
    while(tv<n)
    {
        tv++;
        if(temproot->next!=nullptr)
        temproot=temproot->next;
    }
    //ListNode* temproot=root->next->next;
    while(node!=nullptr)
    {

        tempnext=node->next;
        if(count%n==0)
        {
            int c=n;
            if(flag==false)
            {
                mark=tempnext->next;
                flag=true;
                //c=3;
            }
            ListNode *nodeG=tempnext;
            while(c>=0 && (nodeG)!=nullptr)// && (count+1)>arrsize)
            {
                if(arrsize%n!=0)
                {


                    if(nodeG->next==nullptr)// && nodeG->next->next==nullptr)
                    {
                        break;
                    }
                }
                nodeG=nodeG->next;
                c--;
            }
            t=nodeG;

        }

        node->next=t;
        //cout<<t->num<<" ";
        t=node;
        node=tempnext;
        count++;
    }
    root->next=mark;
    root=temproot;
    //tempnext->next=nullptr;
    //t->next=nullptr;
    //t->next->next=nullptr;
    count=0;
    ListNode* te=root;
    while(count<arrsize-1)
    {
        count++;
        if(te->next!=nullptr)
        {
        te=te->next;
        }
    }
    te->next=nullptr;
    return root;*/
    }
};
