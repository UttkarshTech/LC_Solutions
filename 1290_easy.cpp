int getDecimalValue(ListNode* head) {
    ListNode *temp = head;
    int len = 0;
    while (temp){
        len++;
        temp = temp->next;
    }
    len--;
    temp = head;
    int num = 0;
    while (temp){
        num += temp->val * pow(2, len--);
        temp = temp->next;
    }
    return num;
}