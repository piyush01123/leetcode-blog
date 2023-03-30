# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        curr = head
        data = []
        while curr:
            data.append(curr.val)
            curr = curr.next
        for i in range(len(data)//2):
            if data[i] != data[-1-i]:
                return False
        return True
        # return data == data[::-1]
    