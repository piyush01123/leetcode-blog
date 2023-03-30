class Solution:
    def bitwiseComplement(self, n: int) -> int:
        return (1 << len(bin(n))-2) - n - 1