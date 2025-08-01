ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !(head->next))
        return head;
    ListNode *run = head->next;
    ListNode *fol = head;
    ListNode *folFol = nullptr;
    int curVal = head->val;
    while (run){
        if (run->val != curVal){
            curVal = run->val;
            folFol = fol;
            fol = run;
            run = run->next;
        } else {
            while (run && run->val == curVal)
                run = run->next;
            if (run)
                curVal = run->val; 
            if (folFol)
                folFol->next = run;
            else
                head = run;
            fol = run;
            if (run)
                run = run->next;
        }
    }
    return head;
}