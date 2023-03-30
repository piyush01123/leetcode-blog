"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        A = []
        if root:
            A.append(root.val)
            B=[self.preorder(node) for node in root.children]
            [A.extend(branch) for branch in B]
        return A
        