class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        A = [1]
        for _ in range(rowIndex):
            A = [a+b for a,b in  zip ([0]+A, A+[0])]
        return A
