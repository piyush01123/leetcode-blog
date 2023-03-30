class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # return sorted(s) == sorted(t)
        if len(s)==0 and len(t)==0:
            return True
        if len(s) != len(t):
            return False
        myDict = {}
        for char in s:
            if char in myDict:
                myDict[char] += 1
            else:
                myDict[char] = 1
        # print(myDict)
        for char in t:
            if char in myDict:
                myDict[char] -= 1
            else:
                return False
        if set(myDict.values()) != {0}:
            return False
        return True
        