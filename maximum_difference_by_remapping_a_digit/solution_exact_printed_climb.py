class Solution:
    def minMaxDifference(self, num: int) -> int:
        snum = str(num)
        snumx, snumy = snum, snum
        for i in range(len(snumx)):
            if snumx[i]!='9':
                break
        snumx = snumx.replace(snumx[i],'9')
        snumy = snumy.replace(snumy[0],'0')
        return int(snumx)-int(snumy)