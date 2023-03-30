class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        devices = [row.count('1') for row in bank]
        n = len(bank)
        firstTime = -1
        for i in range(n):
            if devices[i]>0:
                firstTime = i
                break
        if firstTime==-1:
            return 0
        res = 0
        curr = devices[firstTime]
        for i in range(firstTime+1,n):
            if devices[i]==0:
                continue
            res += curr*devices[i]
            curr = devices[i]
        return res
