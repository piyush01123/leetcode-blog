import numpy as np
class Solution:

    def __init__(self, w: List[int]):
        self.probs = [i/sum(w) for i in w]
        self.cumm_probs = [self.probs[0]]
        for p in self.probs[1:]:
            self.cumm_probs.append(p+self.cumm_probs[-1])
        print(self.probs, self.cumm_probs)

    def pickIndex(self) -> int:
        t = np.random.uniform()
        for i in range(len(self.cumm_probs)):
            if self.cumm_probs[i]>t:
                return i
        

# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()