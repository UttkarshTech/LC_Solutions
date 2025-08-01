ListNode* partition(ListNode* head, int x) {
    if (head == 0 || head->next == 0) // case where list contains a single element or no elements
            return head;

        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* p3 = 0;
        ListNode* p4 = 0;

        while (p2 != 0) {
            if (p2->val < x) {
                p1 = p2;
                p2 = p2->next;
                if (p2 == 0) {
                    return head; // case when all list nodes < x
                }
            } else {
                if (p2->next ==
                    0) // case when first element >=x is at the end of the list
                    return head;
                p3 = p2;
                p4 = p2;
                break;
            }
        }
        while (1) {
            p4 = p4->next;
            if (p4 == 0)
                break;
            if (p4->val >= x)
                p3 = p4;
            else {
                if (p1 == p2) { // case when first element >=x is the at the
                                // start of the list
                    p3->next = p4->next;
                    p4->next = p1;
                    p1 = p4;
                    p4 = p3;
                    head = p1;
                } else { // case when the first element >=x is somewhere in the
                         // middle of the list
                    p1->next = p4;
                    p3->next = p4->next;
                    p4->next = p2;
                    p4 = p3;
                    p1 = p1->next;
                }
            }
        }

        return head;
}