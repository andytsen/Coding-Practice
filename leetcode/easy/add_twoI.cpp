struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    long a = 0;
    long b = 0;
    int carry = 0;
    ListNode* res = new ListNode(0);
    ListNode* head = res;
    while(l1 || l2) {
        if(l1 && l2) {
            int c = l1->val + l2->val + carry;
            if(c > 9) {
                c = c % 10;
                carry = 1;
            }
            else
                carry = 0;
            l1 = l1->next;
            l2 = l2->next;
            res->next = new ListNode(c);
            res = res->next;
        }
        else if(!l1 || !l2) {
            ListNode* notNull = l1 ? l1 : l2;
            int c = notNull->val + carry;
            if(c > 9) {
                carry = 1;
                c = 0;
            }
            else
                carry = 0;
            res->next = new ListNode(c);
            res = res->next;
            if(l1)
                l1 = l1->next;
            else
                l2 = l2->next;
        }

    }
    if(carry == 1)
        res->next = new ListNode(1);
    return head->next;

}
