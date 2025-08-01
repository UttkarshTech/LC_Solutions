ListNode* removeElements(ListNode* head, int val) {

    if (head == NULL)
        return head;
    while (head && head->val == val){ //remove delete val from head
        head = head->next;
    }

    ListNode *run = head;
    ListNode *fol = NULL;

    while (run){
        if (run->val == val){
            while (run && run->val == val)
                run = run->next;
            fol->next = run;
            fol = run;
            if (run)
                run = run->next;
        } else {
            fol = run;
            if (run)
                run = run->next;
        }
    }
    return head;
}