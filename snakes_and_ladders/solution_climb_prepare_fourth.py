class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        shortcuts = dict()
        n = len(board)
        for r in range(n):
            for c in range(n):
                if board[r][c]!=-1:
                    if (n-1-r)%2==0:
                        s = n*(n-1-r)+c
                    else:
                        s = n*(n-1-r)+(n-1-c)
                    shortcuts[s] = board[r][c]-1
        graph = [[0 for _ in range(n*n)] for _ in range(n*n)]
        for i in range(n*n):
            for j in range(i+1,min(i+7,n*n)):
                if j in shortcuts:
                    graph[i][shortcuts[j]] = 1
                else:
                    graph[i][j] = 1
        dist = [1e8 for _ in range(n*n)]
        dist[0] = 0
        Q = set(list(range(n*n)))
        while len(Q)>0:
            u, d = min([(i, dist[i]) for i in Q], key=lambda x: x[1])
            Q.remove(u)
            for i in range(n*n):
                if graph[u][i]==1:
                    dist[i] = min(dist[i], dist[u]+1)
        if dist[-1]==1e8: return -1
        return dist[-1]
