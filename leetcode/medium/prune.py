
# leetcode: https://leetcode.com/problems/binary-tree-pruning/description/
# Andy Tseng

class node:
    def __init__(self,x):
        self.data = x
        self.left = None
        self.right = None

def dfs(self, root):
    if not root:
        return None
    left = dfs(root.left)
    if left == 0:
        root.left = None
    right = dfs(root.right)
    if right == 0:
        root.right = None
    if node.data == 0 and not node.left and not node.right:
        return 0
    else:
        return 1

def prune(self, root):
    if dfs(root) == 0:
        return None
    return root


## building the tree wtfff
root = node(1)
root.left = node(0)
root.right = node(1)

leftL1 = root.left
rightL1 = root.right
leftL1.left = node(1)
rightL1.left = node(0)
rightL1.right = node(0)

leftL2 = leftL1.left
leftL2.left = node(0)
leftL2.right = node(1)


