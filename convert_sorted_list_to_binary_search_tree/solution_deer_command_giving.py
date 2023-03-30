# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        A = []
        while head is not None:
            A.append(head.val)
            head = head.next
        return self.arrToBST(A)
        
    def arrToBST(self, alist):
        # print('alist', alist)
        if not alist:
            return None
        mid = len(alist)//2
        btree = TreeNode(alist[mid])
        btree.left = self.arrToBST(alist[:mid])
        btree.right = self.arrToBST(alist[mid+1:])
        return btree
        