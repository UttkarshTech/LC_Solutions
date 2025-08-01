ListNode *detectCycle(ListNode *head) {
    ListNode* fastRunner = head;
    ListNode* slowRunner = head;

    while (fastRunner && fastRunner->next){
        slowRunner = slowRunner->next;
        fastRunner = fastRunner->next->next;

        if (slowRunner == fastRunner){  //cycle detected in list
            slowRunner = head; // point of collision and slowRunner are now equidistant
            while (slowRunner != fastRunner){
                slowRunner = slowRunner->next;
                fastRunner = fastRunner->next;
            }
            return slowRunner;
        }
    }

    return NULL;
}

ListNode *detectCycle(ListNode *head) {
    if (head == 0)
        return NULL;
    unordered_map<ListNode*, int> m;
    ListNode* temp = head;
    int pos = 0;
    while (temp != 0) {
        if (m[temp] >= 1)
            break;
        else {
            m[temp]++;
            pos++;
        }
        temp = temp->next;
    }
    return temp;
}