# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inOrderTraversal(self, root):
        A=[]
        if root:
            A = self.inOrderTraversal(root.left)
            A.append(root.val)
            A.extend(self.inOrderTraversal(root.right))
        return A
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        # P = self.inOrderTraversal(p)
        # Q = self.inOrderTraversal(q)
        # print(P, Q)
        # return P == Q

        if p is None and q is None:
            return True
        
        if p is not None and q is not None:
            if p.val==q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right):
                return True
        return False
            