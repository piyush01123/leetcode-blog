class Solution:
    def executeInstructions(self, n: int, startPos: List[int], s: str) -> List[int]:
        m = len(s)
        res = []
        for i in range(m):
            instructions = s[i:]
            y,x = startPos
            ctr=0
            for ins in instructions:
                if ins=='L': x-=1
                if ins=='R': x+=1
                if ins=='U': y-=1
                if ins=='D': y+=1
                if x<0 or x>=n or y<0 or y>=n:
                    break
                ctr += 1
            res.append(ctr)
        return res