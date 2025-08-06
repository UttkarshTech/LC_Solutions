ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || !head->next)
        return head;
    ListNode *run = head, *start = head, *end, *startPrev = head;
    while (run){
        int temp = k;
        while (run && (temp > 1)){
            run = run->next;
            temp--;
        }
        if (!run)
            return head;
        end = run->next;
        ListNode *rev = start->next;
        ListNode *fol = start;
        // reverse 
        while (rev && rev != end){
            start->next = rev->next;
            rev->next = fol;
            fol = rev;
            rev = start->next;
        }
        if (head == start){
            head = fol;
        } else {
            startPrev->next = fol;
            startPrev = start;
        }
        run = start->next;
        start = start->next;
    }
    return head;
}