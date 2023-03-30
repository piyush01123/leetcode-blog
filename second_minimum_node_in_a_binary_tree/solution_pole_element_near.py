# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preOrderTraversalSet(self, root):
        A = []
        if root is not None:
            # print(A, root.val)
            if root.val not in A:
                A.append(root.val)
            B = self.preOrderTraversalSet(root.left)
            for b in B:
                if b not in A:
                    A.append(b)
            C = self.preOrderTraversalSet(root.right)
            for c in C:
                if c not in A:
                    A.append(c)
        return A
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        A = self.preOrderTraversalSet(root)
        A = sorted(A)
        print('A', A)
        if len(A)<2:
            return -1
        return A[1]
        