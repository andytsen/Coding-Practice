class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

def addTwo(self, l1, l2) {
        carry = 0
        res = ListNode(0);
        head = res;
        while(l1 or l2):
            if(l1 and l2):
                c = l1.val + l2.val + carry
                if(c > 9):
                    c = c % 10
                    carry = 1
                else:
                    carry = 0
                l1 = l1.next
                l2 = l2.next
                res.next = ListNode(c)
                res = res.next
            else:
                if l1:
                    c = l1.val + carry
                    l1 = l1.next
                else:
                    c = l2.val + carry
                    l2 = l2.next
                if(c > 9):
                    c = c % 10
                    carry = 1
                else:
                    carry = 0
                res.next = ListNode(c)
                res = res.next
        if(carry == 1):
            res.next = ListNode(1)
            res = res.next
        return head.next
}
