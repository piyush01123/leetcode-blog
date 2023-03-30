# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # Unused method
    def traverseTree(self, root):
        A=[]
        sum = 0
        if root:
            A = self.traverseTree(root.left)
            A.append(root.val)
            A.extend(self.traverseTree(root.right))
        return A
    
    def isLeaf(self, root):
        return root!=None and root.left==None and root.right==None
    
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # print(self.traverseTree(root))
        res = 0
        if root !=None:
            if self.isLeaf(root.left):
                res += root.left.val
            else:
                res += self.sumOfLeftLeaves(root.left)
            res += self.sumOfLeftLeaves(root.right)
        return res
        