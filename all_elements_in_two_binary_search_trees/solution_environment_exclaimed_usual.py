# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self, root, items):
        if root is None:
            return
        items.append(root.val)
        self.traverse(root.left, items)
        self.traverse(root.right, items)
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        items1, items2 = [], []
        self.traverse(root1, items1)
        self.traverse(root2, items2)
        return sorted(items1+items2)
        