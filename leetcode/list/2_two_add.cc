// you are given two non-empty linked lists representing 
// two non-negative integers. the digits are stored in reverse 
// order and each of their nodes contain a single digit 
// add the two numbers and return it as a linked list 

ListNode* add_two_number(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    int carry = 0;

    while (l1 || l2) {
        int val1 = l1 ? l1->next : 0;
        int val2 = l2 ? l2->next : 0;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry) {
        cur->next = new ListNode(1);
    }
    return dummy->next;
}