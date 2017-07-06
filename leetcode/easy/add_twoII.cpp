#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> a;
    stack<int> b;
    while(l1) {
        a.push(l1->val);
        l1 = l1->next;
    }
    while(l2) {
        b.push(l2->val);
        l2 = l2->next;
    }
    int carry = 0;
    ListNode* pre = nullptr;
    ListNode* res;
    while(!a.empty() || !b.empty()) {
        int c;
        if(!a.empty() && !b.empty()) {
            c = a.top() + b.top() + carry;
            if(c > 9) {
                c = c % 10;
                carry = 1;
            }
            else
                carry = 0;
            a.pop();
            b.pop();
        }
        else {
            c = (a.empty() ? b.top() : a.top()) + carry;
            if(c > 9) {
                c = c % 10;
                carry = 1;
            }
            else
                carry = 0;
            if(a.empty())
                b.pop();
            else
                a.pop();
        }
        res = new ListNode(c);
        res->next = pre;
        pre = res;
    }
    if(carry == 1) {
        res = new ListNode(1);
        res->next = pre;
        pre = res;
    }
    return pre;
}
