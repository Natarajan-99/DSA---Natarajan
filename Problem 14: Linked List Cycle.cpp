#include<unordered_map>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
        {
            return false;
        }
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                return true;
            }
        }
        return false;
        /*ListNode* node=head;
        unordered_map freq<ListNode*,int>;
        while(node!=NULL)
        {
            if(freq.find(node) != freq.end())
            {
                return true;
            }
            freq[node]=1;
            node=node->next;
        }
        return false;*/
    }
};
