class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        nb = bin(n)[2:]
        odd = nb[-2::-2]
        even = nb[-1::-2]
        return [even.count('1'), odd.count('1')]