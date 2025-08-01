ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    if (!headA || !headB)
        return NULL;

    if (headA == headB)
        return headA;

    ListNode *t1 = headA;
    ListNode *t2 = headB;
    int lenA = 0, lenB = 0;
    while (t1){
        lenA++;
        t1 = t1->next;
    }
    while (t2){
        lenB++;
        t2 = t2->next;
    }
    int diff = lenA - lenB;
    t1 = headA;
    t2 = headB;
    if (diff < 0){
        diff *= -1;
        while (diff){
            t2 = t2->next;
            diff--;
        }
    } else {
        while (diff) {
            t1 = t1->next;
            diff--;
        }
    }
    while (t1 || t2){
        if (t1 == t2)
            return t1;
        t1 = t1->next;
        t2 = t2->next;
    }
    return nullptr;
}