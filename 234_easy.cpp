bool isPalindrome(ListNode* head) {
    if (!head)
        return false;
    if (!(head->next))
        return true;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    //slow point to mid
    //fast pointing to last element (odd num of elements)
    // or fast pointing to null (even num of elements)
    ListNode *run = head->next;
    ListNode *fol = head;
    while (run != slow){
        head->next = run->next;
        run->next = fol;
        fol = run;
        run = head->next;
    }
    head->next = NULL;
    ListNode *temp1 = fol;
    ListNode *temp2 = NULL;
    if (fast) //odd number of elements, one middle element
        temp2 = slow->next; 
    else      //even number of elements, two mid elements
        temp2 = slow;
    while (temp1 && temp2){
        if (temp1->val != temp2->val)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (!temp1 && !temp2)
        return true;
    else
        return false;
}