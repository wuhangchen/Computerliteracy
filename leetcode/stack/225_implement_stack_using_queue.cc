class stack {
    std::queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop(void) {
        top();
        q2.pop();
    }

    int top(void) {
        if (q2.empty()) {
            for (int i = 0; i < q1.size(); ++i) {
                q1.push(q1.front());
                q1.pop();
            }
            q2.push(q1.front());
            q1.pop();
        }
        return q2.pop();
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }

};

class stack {
    std::queue<int> q;
public:
    void pop() {
        q.pop();
    }
    void top() {
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
    void push(int x) {
        std::queue<int> temp;
        while(!q.empty()) {
            temp.push(q.front());
            q.pop();
        }
        q.push(x);
        while (!q.empty()) {
            q.push(temp.front());
            temp.pop();
        }
    }
};