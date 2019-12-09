class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
    
def recursion(root, ancestors):
    if root == None:
        return 0
    diffs = []
    for val in ancestors:
        diffs.append(abs(root.val - val))
    cur = max(diffs) if len(diffs) > 0 else 0
    ancestors.append(root.val)
    ancestor_left = ancestors.copy()
    ancestor_right = ancestors.copy()
    return max([cur, recursion(root.left, ancestor_left), recursion(root.right, ancestor_right)])

def max_ancestor_diff(root):
    if root == None:
        return 0
    return recursion(root, [])

## Testing 

n = TreeNode(8)
n.left = TreeNode(3)
n.right = TreeNode(10)

nl = n.left
nl.left = TreeNode(1)
nl.right = TreeNode(6)

nr = n.right
nr.right = TreeNode(14)

nr.right.left = TreeNode(13)
nl.right.left = TreeNode(4)
nl.right.right = TreeNode(7)

print(max_ancestor_diff(n))

q = TreeNode(8)
q.left = TreeNode(1)
q.right = TreeNode(13)
print(max_ancestor_diff(q))

p = TreeNode(8)
print(max_ancestor_diff(p))
