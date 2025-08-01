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