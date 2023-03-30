class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        dic = dict()
        for item in arr:
            if item in dic:
                dic[item]+=1
            else:
                dic[item]=1
        occ = list(dic.values())
        return len(occ) == len(set(occ))