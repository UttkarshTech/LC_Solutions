ListNode* insertionSortList(ListNode* head) {
    if (!head || !(head->next))
        return head;
    ListNode *unsorted = head->next;
    ListNode *fol = head;
    ListNode *tailSorted = head;
    ListNode *run = head;
    while (unsorted){
        run = head;
        fol = unsorted;
        unsorted = unsorted->next;
        if (tailSorted->val <= fol->val)
            tailSorted = fol;
        else {
            while (run->val <= fol->val && run->next && run->next->val <= fol->val)
                run = run->next;
            if (run->val <= fol->val){
                tailSorted->next = unsorted;
                fol->next = run->next;
                run->next = fol;
            }
            else {
                fol->next = run;
                tailSorted->next = unsorted;
                if (head == run)
                    head = fol;
            }
        }
    }
    return head;
}