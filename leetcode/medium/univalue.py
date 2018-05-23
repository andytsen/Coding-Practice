# 

class TreeNode(object):
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

def longest_univalue(self,root):
    """
    :type root: TreeNode
    :rtype: int
    """

    ans = 0
    def path(root):
        if root == None:
            return 0
        left = path(root.left)
        right = path(root.right)
        if(root.left != None and root.left.val == root.val):
            left += 1
        if(root.right != None and root.right.val == root.val):
            right += 1
        ans = max(ans, right+left)
        return max(right,left)
    path(root)
    return ans 

def main():



