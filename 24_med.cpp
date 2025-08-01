ListNode* swapPairs(ListNode* head) {
    if (head == 0 || head->next == 0)
        return head;
    ListNode* p1 = head;
    ListNode* p2 = head->next;
    ListNode* t = new ListNode(0);
    while (p1 != 0 && p2 != 0) {
        p1->next = p2->next;
        p2->next = p1;
        if (p1 == head)
            head = p2;
        t->next = p2;
        if (p1->next == 0)
            p2 = 0;
        else
            p2 = p1->next->next;
        t = p1;
        p1 = p1->next;
    }
    return head;
}