class Solution:
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        # print(rec1[0]>=rec2[2], rec2[0]>=rec1[2], rec1[1]>=rec2[3], rec2[1]>=rec1[3])
        if rec1[0]>=rec2[2] or rec2[0]>=rec1[2] or rec1[1]>=rec2[3] or rec2[1]>=rec1[3]:
            return False
        return True
        