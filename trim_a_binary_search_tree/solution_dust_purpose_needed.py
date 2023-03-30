# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inOrderTraversal(self, root):
        A = []
        if root:
            A = self.inOrderTraversal(root.left)
            A.append(root.val)
            A.extend(self.inOrderTraversal(root.right))
        return A
    
    def insertNode(self, root, val):
        if root.val is None:
            # print('Inserted at ROOT')
            root.val = val
        elif val < root.val:
            # print(root.val, val, 'less')
            if root.left is None:
                root.left = TreeNode(val)
                # print('Inseted at LEFT')
            else:
                self.insertNode(root.left, val)
        else:
            # print(root.val, val, 'more')
            if root.right is None:
                root.right = TreeNode(val)
                # print('Inserted at RIGHT')
            else:
                self.insertNode(root.right, val)
    
    def createTree(self, vals):
        if len(vals)==0:
            return None
        mid = len(vals)//2
        tree = TreeNode(vals[mid])
        tree.left = self.createTree(vals[:mid])
        tree.right = self.createTree(vals[mid+1:])
        return tree

    def arrToBST(self, alist):
        # print('alist', alist)
        if not alist:
            return None
        mid = len(alist)//2
        btree = TreeNode(alist[mid])
        btree.left = self.arrToBST(alist[:mid])
        btree.right = self.arrToBST(alist[mid+1:])
        return btree
    
    
    # def trimBST(self, root, L, R):
    #     """
    #     :type root: TreeNode
    #     :type L: int
    #     :type R: int
    #     :rtype: TreeNode
    #     """
    #     A = self.inOrderTraversal(root)
    #     B = [a for a in A if a>=L and a<=R]
    #     print('A = %s, B = %s' %(A, B))
    #     return self.arrToBST(B)
        
    def trimBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: TreeNode
        """
        if root is None:
            return None
        left = self.trimBST(root.left, L, R)
        right = self.trimBST(root.right, L, R)
        if root.val>=L and root.val<=R:
            root.left = left
            root.right = right
            return root
        return left if left is not None else right
        
        