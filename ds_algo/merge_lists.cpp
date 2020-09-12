class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *head=NULL,*temp;
        int n;
        while(l1!=NULL&&l2!=NULL)
        {
            if(l1->val<=l2->val)
            {
                n=l1->val;
                l1=l1->next;
            }
            else
            {
                n=l2->val;
                l2=l2->next;
            }
            if(!head)
            {
                head= new ListNode(n);
                temp=head;
            }
            else
            {
                temp->next=new ListNode(n);
                temp=temp->next;
            }
        }
        while(l1)
        {
            if(!head)
            {
                head=new ListNode(l1->val);
                temp=head;
            }
            else{
            temp->next=new ListNode(l1->val);
                temp=temp->next;
            }
            l1=l1->next;
        }
        while(l2)
        {
            if(!head)
            {
                head=new ListNode(l2->val);
                temp=head;
            }
            else {
            temp->next=new ListNode(l2->val);
                temp=temp->next;
            }
            l2=l2->next;
        }
        return head;
    }
};
