class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def max_bst(nums):
    if len(nums) == 0:
        return None
    if len(nums) == 1:
        return TreeNode(nums[0])
    j = nums.index(max(nums))
    node = TreeNode(nums[j])
    node.left = max_bst(nums[:j])
    node.right = max_bst(nums[j+1:])
    return node


tn = max_bst([3,2,1,6,0,5])

print(tn.val)
print(tn.left.val)
print(tn.right.val)

