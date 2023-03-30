# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inOrderTraversal(self, root):
        A=[]
        if root is not None:
            A = self.inOrderTraversal(root.left)
            A.append(root.val)
            A.extend(self.inOrderTraversal(root.right))
        return A
    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # works only if all keys in tree are unique or
        # definition of bst includes equal key
        A = self.inOrderTraversal(root)
        return A==sorted(A) and len(A) == len(set(A))
        
        # if root is None:
        #     return True
        # print(root.val)
        # if root.left is not None:
        #     if root.left.val < root.val:
        #         self.isValidBST(root.left)
        #     else:
        #         return False
        # if root.right is not None:
        #     if root.right.val > root.val:
        #         self.isValidBST(root.right)
        # else:
        #     return False
        # # return True