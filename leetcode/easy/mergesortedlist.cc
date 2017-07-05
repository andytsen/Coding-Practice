class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* cur = (l1->val < l2->val) ? l1 : l2;
            while(l1 || l2) {
                if(l1->val > l2->val) {


                }
            }
        }
};
