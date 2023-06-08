ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(curr!=nullptr){
            ListNode* newnode = curr->next;
            curr->next=prev;
            prev = curr;
            curr=newnode;
        }
        head = prev;
        return head;
    }