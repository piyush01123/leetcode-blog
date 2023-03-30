class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        if m*n!=r*c: return mat
        data = [None for _ in range(m*n)]
        for i in range(m):
            for j in range(n):
                data[n*i+j] = mat[i][j]
        mat_res = [[None for _ in range(c)] for _ in range(r)]
        for i in range(r):
            for j in range(c):
                mat_res[i][j] = data[c*i+j]
        return mat_res