ListNode* deleteDuplicates(ListNode* head) {
        
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *temp = head;
    ListNode *follow = head;
    int curVal = -99999;

    while (temp){
        if  (curVal != temp->val){
            curVal = temp->val;
            if (follow != temp)
                follow->next = temp;
            follow = temp;
            temp = temp->next;
        } else
            temp = temp->next;
    }
    follow->next = NULL;
    return head;
}