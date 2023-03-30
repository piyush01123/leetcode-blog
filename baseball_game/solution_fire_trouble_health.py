class Solution:
    def calPoints(self, ops: List[str]) -> int:
        score = []
        for s in ops:
            try:
                score.append(int(s))
            except:
                if s=='C': score.pop()
                if s=='D': score.append(score[-1]*2)
                if s=='+': score.append(score[-2]+score[-1])
        return sum(score)