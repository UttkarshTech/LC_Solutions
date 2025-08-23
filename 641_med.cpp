class MyCircularDeque {
    vector<int> dq;
    int maxSize, front = -1, end = -1;
    public:
    MyCircularDeque(int k) {
        maxSize = k;
        dq.assign(k, -1);
    }

    bool insertFront(int value) {
        if (front == -1){
            dq[++front] = value;
            end = (front + 1) % maxSize;
            return true;
        } else if (front == end)
            return false;
        else {
            front = (front == 0) ? maxSize - 1 : front - 1;
            dq[front] = value;
            return true;
        }
    }

    bool insertLast(int value) {
        if (end == -1) {
            dq[++end] = value;
            end = (end+1)%maxSize;
            front = 0;
            cout<<end<<front;
            return true;
        }
        else if(end == front)
            return false;
        else {
            dq[end] = value;
            end = (end + 1) % maxSize;
            return true;
        }
    }

    bool deleteFront() {
        if (front == -1)
            return false;
        else {
            dq[front] = -1;
            front = (front + 1)%maxSize;
            if (front == end)
                front = end = -1;
            return true;
        }
    }

    bool deleteLast() {
        if (end == -1)
            return false;
        else {
            end = (end == 0) ? maxSize-1 : end - 1;
            dq[end] = -1;
            if (end == front)
                end = front = -1;
            return true;
        }
    }

    int getFront() {
        if (front == -1)
            return -1;
        else 
            return dq[front];
    }

    int getRear() {
        if (end == -1)
            return -1;
        else 
            return dq[(end == 0) ? maxSize-1 : end-1];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        if (front == -1)
            return false;
        return front == end;
    }
};