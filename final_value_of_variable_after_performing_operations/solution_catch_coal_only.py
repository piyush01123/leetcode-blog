class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        L = [-1 if op[1]=='-'  else 1 for op in operations]
        return sum(L)