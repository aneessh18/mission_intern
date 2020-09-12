class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(n==0)
            return head;
        int j=0;
        ListNode *temp1=head,*temp2=head;
        while(j<n)
        {
            temp1=temp1->next;
            j++;
        }
        if(temp1==NULL)
            return head->next;
        while(temp1->next)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        temp2->next=temp2->next->next;
        return head;
    }
};
