ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (head == 0 || head->next == 0) //case where empty or single element linked list
        return head;
    if (left == right)
        return head;
    ListNode* t1 = head;
    ListNode* t2 = 0;
    for (int i=0; i<left-1; i++){
        cout<<"XXX"<<endl;
        t2 = t1;
        t1 = t1->next;
        if (t1 == 0)    //case out of bound left value
            return head;
        if (t1->next == 0)
            return head; //case last element is left, nothing to reverse
    }
    ListNode* p1 = t1;
    ListNode* p2 = t1->next;

    for (int i=0; i<right-left; i++){
        t1->next = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = t1->next;
    }

    if (t2 == 0)
        head = p1;
    else
        t2->next = p1;
    
    return head;
}