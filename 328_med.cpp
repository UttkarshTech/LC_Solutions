ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next || !head->next->next)
        return head;
    ListNode *oddTail, *evenHead, *run, *fol;
    evenHead = fol = head->next;
    oddTail  = head;
    run = head->next->next;
    bool flag = false;
    while (run){
        if (flag){
            fol = run;
            run = run->next;
        } else {
            fol->next = run->next;
            run->next = evenHead;
            oddTail->next = run;
            oddTail = run;
            run = fol->next;
        }
        flag = !flag;
    }
    return head;
}