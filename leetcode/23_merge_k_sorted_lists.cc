// merge k sorted linked lists and return it as one sorted list, analyze and describe its complexity;

ListNode* merge_k_lists(std::vector<ListNode*> &lists) {
    std::priority_queue<ListNode* , std::vector<ListNode*>, cmp> q;
    for (int i = 0; i < lists.size(); ++i) {
        if (lists[i]) {
            q.push(lists[i]);
        }
    }
    ListNode* head = nullptr, *pre = nullptr, *tmp = nullptr;
    while(!q.empty()) {
        tmp = q.top();
        q.pop();
        if (!pre) {
            head = tmp;
        } else {
            pre->next = tmp;
        }
        pre = tmp;
        if (tmp ->next) {
            q.push(tmp->next);
        }
    }
    return head;
}

struct cmp{
    bool operate()(const ListNode* a, const LIstNode* b) {
        return a->val > b->val;
    }
}




// version two 

ListNode* merge_k_lists(std::vector<ListNode*>& lists) {
    if (lists.size() == 0) {
        return nullptr;
    }
    int n = lists.size();
    while (n > 1) {
        int k = (n + 1) / 2;
        for (int i = 0; i < n / 2; ++i) {
            lists[i] = merger_two_lists(lists[i], lists[i + k])
        }
        n = k;
    }
    return lists[0];
}

ListNode* merge_two_lists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1);
    ListNode* cur = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cut = cur->next;
    }
    if (l1) {
        cur->next = l1;
    }
    if (l2) {
        cur->next = l2;
    }

    return head->next;
}


