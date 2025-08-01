ListNode* removeNthFromEnd(ListNode* head, int n) {

    if (!head || (!(head->next) && n>0))
        return 0;
    

    ListNode *t1 = head;
    ListNode *t2 = head;
    ListNode *follow = head;

    while (n>0){
        t2 = t2->next;
        n--;
    }

    while (t2){
        follow = t1;
        t1 = t1->next;
        t2 = t2->next;
    }

    if (t1 == head){
        head = head->next;
    } else {
        follow->next = t1->next;
    }

    return head;
}