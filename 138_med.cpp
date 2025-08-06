Node* copyRandomList(Node* head) {
    if (!head)
        return head;
    if (!head->next){
        Node *newNode = new Node(head->val);
        if (head->random == head)
            newNode->random = newNode;
        return newNode;
    }
    Node *run = head;
    while (run){
        Node *newNode = new Node(run->val);
        newNode->next = run->next;
        run->next = newNode;
        run = run->next->next;
    }
    run = head;
    while (run){
        if (!run->random)
            run->next->random = NULL;
        else
            run->next->random = run->random->next;
        run = run->next->next;
    }
    Node *newHead = head->next;
    run = head;
    while (run){
        if (run->next && run->next->next){
            Node *temp = run->next->next;
            run->next->next = run->next->next->next;
            run->next = temp;
            run = temp;
        } else{
            run->next = NULL;
            run = NULL;
        }
    }
    return newHead;
}

Node* copyRandomList(Node* head) {
    if (!head)
        return head;
    if (!head->next){
        Node *newNode = new Node(head->val);
        if (head->random)
        newNode->random = newNode;
        return newNode;
    }

    Node *temp = head;
    Node *newHead = NULL;
    Node *newTemp = NULL;

    //shallow copy
    while (temp){
        Node *newNode = new Node(temp->val);
        if (!newHead){
            newHead = newNode;
            newTemp = newHead;
        } else {
            newTemp->next = newNode;
            newTemp = newNode;
        }
        temp = temp->next;
    }

    temp = head;
    newTemp = newHead;

    while (temp){
        if (temp->random){
            int pos = 1;
            Node *run = head;
            while (run != temp->random){
                run = run->next;
                pos++;
            }
            run = newHead;
            while (--pos){
                run = run->next;
            }
            newTemp->random = run;
        }
        temp = temp->next;
        newTemp = newTemp->next;
    }
    return newHead;

}