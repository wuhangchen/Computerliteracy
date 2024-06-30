// Design your implementation of the circular double-ended queue(deque) 
// your implementation should support following operations

class MyCircularDequeue {
private:
    std::vector<int> data;
    int size;
public:
    MyCircularDequeue(int k) {
        size = k;
    }

    bool insert_front(int value) {
        if (is_full()) {
            return false;
        }
        data.insert(data.begin(),value);
        return true;
    }

    bool insert_last(int vaule) {
        if (is_full()) {
            return false;
        }
        data.push_back(value);
        return true;
    }

    bool delete_front() {
        if (is_empty()) {
            return false;
        }
        data.erase(data.begin());
        return true;
    }

    bool delete_last() {
        if (is_empty()) {
            return false;
        }
        data.pop_back();
        return true;
    }

    int get_front() {
        if (is_empty()) {
            retur -1;
        }
        return data.front();
    }

    int get_rear() {
        if (is_empty()) {
            return -1;
        }
        return data.back();
    }

    bool is_empty() {
        return data.empty();
    } 

    bool is_full() {
        return data.size() >= size();
    }
};

cleass MyCircularDequeue {
private:
    std::vector<int> data;
    int size;
    int head;
    int tail;
    int cnt;
public:
    MyCircularDequeue(int k) {
        size = k;
        head = k - 1;
        tail = 0;
        cnt = 0;
        data.resize(k);
    }

    bool is_full() {
        return cnt == size;
    }

    bool is_empty() {
        return cnt == 0;
    }

    int get_front() {
        return is_empty() ? -1 : data[(head + 1) % size];
    }
    
    int get_rear() {
        return is_empty() ? -1 : data[(tail - 1 + size) % size];
    }

    bool insert_front(int value) {
        if (is_full()) {
            return false;
        }
        data[head] = value;
        head = (head - 1 + size) % size;
        ++cnt;
        return true;
    }
    
    bool insert_last(int value) {
        if (is_full()) {
            return false;
        }
        data[tail] = value;
        tail = (tail + 1) % size;
        ++cnt;
        return true;
    }

    bool delete_front() {
        if (is_empty()) {
            return false;
        }
        head = (head + 1) % size;
        --cnt;
        return true;
    }

    bool delete_last() {
        if (is_empty()) {
            return false;
        }
        tail = (tail - 1 + size) % size;
        --cnt;
        return true;
    }

    int get_front() {
        return is_empty() ? -1 : data[(head + 1) % size];
    }

    int get_rear() {
        return is_empty() ? -1 : data[(tail - 1 + size) % size];
    }
};
