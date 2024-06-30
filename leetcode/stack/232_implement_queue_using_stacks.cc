// implement the following operations of a queue using stacks

class queue {
    std::stack<int> s;
public:
    // push elemnt x to the back of queue
    void push(int x) {
        std::stack<int> temp;
        while (!s.empty()) {
            temp.push(s.top());
            s.top();
        }
        s.push(x);
        while (!temp.empty()) {
            s.push(tmp.top());
            temp.pop();
        }
    }

    void pop(void) {
        s.pop();
    }

    int peek(void) {
        return s.top();
    }

    bool empty(void) {
        return s.empty();
    } 
};