class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        dic = {}
        for item in arr:
            if item not in dic:
                dic[item] = 1
            else:
                dic[item] += 1
        return max(dic, key=lambda k: dic[k])