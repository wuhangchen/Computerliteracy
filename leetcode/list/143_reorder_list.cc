// Given a singly list , You may modify the values in the 
// list's nodes, only nodes itself may be changed 

void reorder_list(ListNode* head) {
    if (!head || !head->next || !head->next->next) {
        return ;
    }

    // split first second list 
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    
    // reverse second list 
    ListNode* last = mid;
    ListNode* pre = nullptr;
    while (last) {
        ListNode* next = last->next;
        last->next = pre;
        pre = last;
        last = next;
    }
    
    // insert second list to first
    while (head && pre) {
        ListNode* next = head->next;
        head->next = pre;
        pre = pre->next;
        head->next->next = next;
        head = next;
    }
}