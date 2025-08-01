ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    //out of place solution, Space Complexity O(n), Time Complexity O{n}

    if (list1 == 0){ //cases where either list is empty or both are empty
        if (list2 == 0)
            return 0;
        else 
            return list2;
    }
    else {
        if (list2 == 0)
            return list1;
    }

    ListNode *temp1 = list1;
    ListNode *temp2 = list2;
    
    ListNode *head;
    if (temp1->val <= temp2->val){  //Init head
        head = temp1;
        temp1 = temp1->next;
    }
    else{
        head = temp2;
        temp2 = temp2->next;
    }
    
    ListNode *temp3 = head;

    while (temp1 && temp2){
        if (temp1->val <= temp2->val){
            temp3->next = temp1;
            temp1 = temp1->next;
        } else {
            temp3->next = temp2;
            temp2 = temp2->next;
        }
        temp3 = temp3->next;
    }
    
    if (temp1)
        temp3->next = temp1;
    if (temp2)
        temp3->next = temp2;

    return head;
}