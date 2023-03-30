import numpy as np

def matrix_multiply(mat1, mat2):
    m1, n1 = len(mat1), len(mat1[0])
    m2, n2 = len(mat2), len(mat2[0])
    assert n1==m2
    product = [[None for _ in range(n2)] for _ in range(m1)]
    for i in range(m1):
        for j in range(n2):
            s = 0
            for k in range(m2):
                s+=mat1[i][k]*mat2[k][j]
            product[i][j] = s
    return product

def matrix_power(mat, p):
    if p==1: return mat
    mat_p2 = matrix_power(mat, p//2)
    if p%2==0:
        return matrix_multiply(mat_p2, mat_p2)
    else:
        return matrix_multiply(matrix_multiply(mat_p2, mat_p2), mat)

class Solution:
    def countVowelPermutation(self, n: int) -> int:
        if n==1: return 5
        M = [[0,1,1,0,1],
             [1,0,1,0,0],
             [0,1,0,1,0],
             [0,0,1,0,0],
             [0,0,1,1,0]
            ]
        M_f = matrix_power(M,n-1)
        return sum([sum(i) for i in M_f]) % 1000000007
