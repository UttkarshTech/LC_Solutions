ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (1){
        fast  = fast->next;
        if (fast == 0)
            return slow;
        slow = slow->next;
        fast = fast->next;
        if (fast == 0)
            return slow;
    }
}