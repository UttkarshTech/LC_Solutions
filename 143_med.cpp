void reorderList(ListNode* head) {
    //nothing to be done if null, one or two elements
    if (!head || !(head->next) || !(head->next->next))
        return;
    

    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *tail = NULL;
    while (fast && fast->next){
        slow = slow->next;
        if (!fast->next->next)
            tail = fast->next; //save last position in case of even number of elements
        fast = fast->next->next;
    }
    if (fast)
        tail = fast;
    // slow points at mid of list
    // fast points at last element if odd number of elements in the list
    // fast points at null is even number of elements in the list
    ListNode *run = slow->next;
    ListNode *fol = slow;
    while (run){
        slow->next = run->next;
        run->next = fol;
        fol = run;
        run = slow->next;
    }
    slow->next = NULL;
    //tail points at last element;
    run = head->next;
    fol = head;
    ListNode *runRev = tail->next;
    ListNode *folRev = tail;
    while (runRev != slow){
        fol->next = folRev;
        folRev->next = run;
        fol = run;
        run = run->next;
        folRev = runRev;
        runRev = runRev->next;
    }
    if (run == slow) //case of odd, run == slow and runrev == slow
        fol->next = folRev;
    else { //case of even, runRev == slow only
        fol->next = folRev;
        folRev->next = run;
    }
}