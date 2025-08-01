ListNode* reverseList(ListNode* head) {
    if (!head || !(head->next))
        return head;
    ListNode *run = head->next;
    ListNode *end = head;
    while (run){
        head->next = run->next;
        run->next = end;
        end = run;
        run = head->next;
    }
    head = end;
    return head;
}