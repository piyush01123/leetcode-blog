class Solution:
    def minOperations(self, boxes: str) -> List[int]:
        answer = []
        N = len(boxes)
        for i in range(N):
            ctr = 0
            for j in range(N):
                if i==j:
                    continue
                if boxes[j]=='1':
                    ops = abs(j-i)
                    ctr+=ops
            answer.append(ctr)
        return answer