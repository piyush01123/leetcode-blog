class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)
        matrixT = [[row[i] for row in matrix] for i in range(n)]
        # S = n*(n+1)//2
        # return all([sum(row)==sum(rowT)==S for row,rowT in zip(matrix,matrixT)])
        for row in matrix:
            for i in range(1,n+1):
                if i not in row:
                    return False
        for rowT in matrixT:
            for i in range(1,n+1):
                if i not in rowT:
                    return False
        return True

            
