"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        A = []
        if root is not None:
            for child in root.children:
                A.extend(self.postorder(child))
            A.append(root.val)
        return A
        