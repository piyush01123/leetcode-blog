# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def preOrderOrig(self, root):
        A = []
        if root is not None:
            A.append(root.val)
            A.extend(self.preOrderOrig(root.left))
            A.extend(self.preOrderOrig(root.right))
        return A

    def preOrder(self, root):
        A = []
        if root is not None:
            A.append(root.val)
            if root.left is not None:
                A.extend(self.preOrder(root.left))
            else:
                A.append(None)
            if root.right is not None:
                A.extend(self.preOrder(root.right))
            else:
                A.append(None)
            return A
        else:
            return None
        

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        A =  self.preOrder(root)
        if A is None:
            return None
        return ','.join(list(map(str, A)))

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data is None:
            return None
        def helper(lst):
            first = lst.pop(0)
            if first is None:
                return None
            else:
                root = TreeNode(first)
                root.left = helper(lst)
                root.right = helper(lst)
                return root

        A = data.split(',')
        A = [int(a) if a!='None' else None for a in A ]
        return helper(A)

        # print('DATA', data)
        # A = data.split(',')
        # A = [int(a) if a!='None' else None for a in A ]
        # f = A.pop(0)
        # if f is None:
        #     return None
        # else:
        #     root = TreeNode(f)
        #     print('A = ', A)
        #     root.left = self.deserialize(','.join(list(map(str, A))))
        #     root.right = self.deserialize(','.join(list(map(str, A))))
        #     return root
        
        
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))