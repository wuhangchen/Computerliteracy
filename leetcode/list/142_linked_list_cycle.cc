// given a linked list , return the node where the cycle 
// begins . if there is no cycle return null 

int detect_cycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (!fast || !fast->next) {
        return nullptr;
    }
    slow = head;
    size_t i = 0;
    while (slow != fast) {
        i++;
    }
    return i;
}
