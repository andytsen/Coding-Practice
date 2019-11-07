## Objects are pointers in python?


class node:
    def __init__(self, value, next_node):
        self.value = value
        self.next_node = next_node
    def __init(self, value):
        self.value = value
        self.next_node = None

class LinkedList:
    def __init__(self):
        self.head = None

    def reverse_list(self):
        prev = None
        while self.head != None:
            next_ptr = self.head.next_node
            self.head.next_node = prev
            prev = self.head
            self.head = next_ptr
        self.head = prev

    def print_list(self):
        cur = self.head
        while cur != None:
            print(cur.value)
            cur = cur.next_node

    def build_list(self,values):
        cur = None
        for v in values:
            if cur == None:
                cur = node(v,None)
            else:
                node_inst = node(v,None)
                cur.next_node = node_inst
                cur = node_inst
            if self.head == None:
                self.head = cur

ll = LinkedList()
ll.build_list([1,2,3,4,5])
ll.print_list()
ll.reverse_list()
ll.print_list()

l1 = [1,2,3]

        


        
