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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        else
        {
        ListNode *o,*e,*t;
        o=head;
        e=head->next;
        ListNode *n=new ListNode;
        n->val=o->val;
        n->next=NULL;
        t=n;
        while(o->next!=NULL)
        {
            o=o->next->next;
            if(o==NULL)
            {
                break;
            }
            ListNode *temp=new ListNode(o->val);
            temp->next=NULL;
            n->next=temp;
            n=n->next;
            //n->next=NULL;
        }
        ListNode *temp=new ListNode(e->val);
        temp->next=NULL;
        n->next=temp;
        n=n->next;
        //n->next=NULL;
        while(e->next!=NULL)
        {
            e=e->next->next;
            if(e==NULL)
            {
                break;
            }
            ListNode *temp=new ListNode(e->val);
            temp->next=NULL;
            n->next=temp;
            n=n->next;
            //n->next=NULL;
        }
        return t;
        }
    }
};
