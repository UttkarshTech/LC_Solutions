ListNode* rotateRight(ListNode* head, int k) {
    if (!head)
        return head;
    ListNode *temp = head;
    int len = 0;
    while (temp){
        len++;
        temp = temp->next;
    }
    k %= len;
    if (k == 0){
        return head;
    }
    int pos = len - k;
    temp = head;
    ListNode *fol = head;
    while (pos > 0){
        fol = temp;
        temp = temp->next;
        pos--;
    }
    fol->next = 0;
    ListNode *mark = temp;
    while (temp->next)
        temp = temp->next;
    temp->next = head;
    head = mark;
    return head;
}