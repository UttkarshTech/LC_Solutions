ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *run1 = list1, *run2 = list2;
    if (!list1 && !list2)
        return list1;
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    ListNode *sorted;
    bool flag = false;
    if (list1->val <= list2->val){
        sorted = list1;
        run1 = run1->next;
        flag = true;
    }
    else {
        sorted = list2;
        run2 = run2->next;
    }
    while (run1 && run2){
        if (run1->val <= run2->val) {
            sorted->next = run1;
            sorted = sorted->next;
            run1 = run1->next;
        } else {
            sorted->next = run2;
            sorted = sorted->next;
            run2 = run2->next;
        }
    }
    if (!run1)
        sorted->next = run2;
    if (!run2)
        sorted->next = run1;
    if (flag)
        return list1;
    else
        return list2;
}