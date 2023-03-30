class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        n = len(mat)
        t1 = [[mat[n-1-j][i] for j in range(n)] for i in range(n)]
        t2 = [[t1[n-1-j][i] for j in range(n)] for i in range(n)]
        t3 = [[t2[n-1-j][i] for j in range(n)] for i in range(n)]
        if mat==target:
            return True
        if t1==target:
            return True
        if t2==target:
            return True
        if t3==target:
            return True
        return False


        