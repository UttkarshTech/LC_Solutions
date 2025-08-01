ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (!l1 && !l2)
        return 0;
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    ListNode *head = new ListNode(temp1->val + temp2->val);
    bool carry = false;
    if (temp1->val + temp2->val >= 10){
        head->val %= 10;
        carry = true;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
    ListNode *temp3 = head;
    while (temp1 && temp2){
            ListNode *newNode = new ListNode(0);
        if (carry == true){
            newNode->val = temp1->val + temp2->val + 1;
            carry = false;
        } else{
            newNode->val = temp1->val + temp2->val;
        }
        if (newNode->val >= 10){
            newNode->val %= 10;
            carry = true;
        }
        temp3->next = newNode;
        temp3 = temp3->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1 == 0){
        while (temp2){
            ListNode *newNode = new ListNode(0);
            if (carry){
                newNode->val = temp2->val + 1;
                carry = false;
            }
            else
                newNode ->val = temp2->val;
            if (newNode->val >= 10){
                newNode->val %= 10;
                carry = true;
            }
            temp3->next = newNode;
            temp3 = temp3->next;
            temp2 = temp2->next;
        }
    }
    if (temp2 == 0){
        while (temp1){
            ListNode *newNode = new ListNode(0);
            if (carry){
                newNode->val = temp1->val + 1;
                carry = false;
            }
            else
                newNode ->val = temp1->val;
            if (newNode->val >= 10){
                newNode->val %= 10;
                carry = true;
            }
            temp3->next = newNode;
            temp3 = temp3->next;
            temp1 = temp1->next;
        }
    }
    if (carry){
        ListNode *newNode = new ListNode(1);
        temp3->next = newNode;
    }
    return head;
}