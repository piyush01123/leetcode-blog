class Solution:
    # def lengthOfLongestSubstring(self, s):
    #     """
    #     :type s: str
    #     :rtype: int
    #     """
    #     if len(s)==0:
    #         return 0
    #     charsSeen = []
    #     lengths = []
    #     i=0
    #     l=0
    #     for char in s:
    #         if char in charsSeen:
    #             lengths.append(l)
    #             charsSeen = charsSeen[charsSeen.index(char) + 1:]
    #             l=len(charsSeen) + 1
    #         else:
    #             l+=1
    #         charsSeen.append(char)
    #         i+=1
    #         # print(charsSeen, lengths, l)
    #     lengths.append(l)
    #     # print(lengths)
    #     return max(lengths)

    def lengthOfLongestSubstring(self, s):
        n = len(s)
        mySet= set()
        ans = 0
        i = 0
        j = 0
        while i<n and j< n:
            if s[j] not in mySet:
                mySet.add(s[j])
                j+=1
                ans = max(ans, j-i)
            else:
                mySet.remove(s[i])
                i+=1
        return ans

    