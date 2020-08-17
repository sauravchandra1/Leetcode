class MyCircularQueue {
    public:
        /** Initialize your data structure here. Set the size of the queue to be k. */
        int front = -1;
        int back = -1;
        vector < int > q;
        int k;
        int size = 0;
        MyCircularQueue(int k) {
            q.resize(k, -1);
            this -> k = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (front == -1 && back == -1) {
            front++;
            back++;
            q[0] = value;
            size++;
            return true;
        }
        if (q[(back + 1) % k] == -1) {
            back = (back + 1) % k;
            q[back] = value;
            size++;
            return true;
        }
        return false;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (front == -1)
            return false;
        if (q[front % k] == -1)
            return false;
        q[front] = -1;
        front = (front + 1) % k;
        size--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (front == -1) return -1;
        return q[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (back == -1)
            return -1;
        return q[back];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == k;
    }
};