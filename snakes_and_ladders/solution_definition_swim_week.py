class Solution:
    def get_row_col(self, index):
        n = self.n
        row = n-1-index//n
        if (n-1-row)%2==0:
            col = index%n
        else:
            col = n-1-index%n
        return row, col
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n = len(board)
        self.n = n
        graph = []
        for i in range(n*n):
            for j in range(i+1, min(i+7,n*n)):
                row, col = self.get_row_col(j)
                if board[row][col]!=-1:
                    graph.append([i,board[row][col]-1])
                else:
                    graph.append([i,j])
        dist = [1e8 for _ in range(n*n)]
        dist[0] = 0
        Q = set(list(range(n*n)))
        while len(Q)>0:
            u,d = min([(i,dist[i]) for i in Q], key=lambda i: i[1])
            Q.remove(u)
            for edge in graph:
                if edge[0]==u:
                    dist[edge[1]] = min(dist[edge[1]], dist[u]+1)
        if dist[-1] == 1e8: return -1
        return dist[-1]
            