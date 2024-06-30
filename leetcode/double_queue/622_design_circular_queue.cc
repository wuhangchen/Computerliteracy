// Design your implementation of the circular queue .

class MyCircularQueue {
private:
    std::vector<int> data;
    int size;
public: 
    MyCircularQueue(int k) {
        size = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data.push_back(value);
        return true;
    }

    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        data.erase(data.begin());
        return true;
    } 

    int front() {
        if (isEmpty()) {
            return -1;
        }
        return data.front();
    }

    int rear() {
        if (isEmpty()) {
            return -1;
        }
        return data.back();
    }

    bool isEmpty() {
        return data.empty();
    }

    bool isFull() {
        return data.size() >= size();
    }
};


class MyCircularQueue {
private: 
    std::vector<int> data;
    int size;
    int cnt;
    int head;
    int tail;
public:
    MyCircularQueue(int k ) {
        size = k;
        head = k - 1;
        tail = 0;
        cnt = 0;
        data.resize(k);
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        data[tail] = value;
        tail = (tail + 1) % size;
        ++cnt;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        head = (head + 1) $ size;
        --cnt;
        return true;
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }
        return data[(head + 1) % size];
    }

    int rear() {
        if (isEmpty()) {
            return -1;
        }
        return data[(tail - 1 + size) % size];
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == size;
    }
};
