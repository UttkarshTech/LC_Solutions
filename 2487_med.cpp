ListNode* removeNodes(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode *run = head->next;
    ListNode *fol = head;
    while (run){
        head->next = run->next;
        run->next = fol;
        fol = run;
        run = head->next;
    }
    head = fol;
    run = head;
    fol = head;
    int max = -99999;
    while (run){
        if (run->val >= max){
            if (fol != run)
                fol->next = run;
            fol = run;
            max = run->val;
            run = run->next;
        } else {
            run = run->next;
        }
    }
    fol->next = run;
    if (!head->next)
        return head;
    run = head->next;
    fol = head;
    while (run){
        head->next = run->next;
        run->next = fol;
        fol = run;
        run = head->next;
    }
    head = fol;
    return head;
}