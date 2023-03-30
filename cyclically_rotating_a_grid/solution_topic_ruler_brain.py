class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        grid_data = grid.copy()
        grid = [[n*i+j for j in range(n)] for i in range(m)]
        gridI = grid[::-1]
        gridT = [[None for _ in range(m)] for _ in range(n)]
        for i in range(m):
            for j in range(n):
                gridT[j][i] = grid[i][j]
        gridTI = gridT[::-1]
        # print("MN", m,n)
        # print("ORG", grid)
        # print("ORGI", gridI)
        # print("ORGT", gridT)
        # print("ORGTI", gridTI)

        rows = []
        for i in range(m//2):
            row = grid[i][min(i,n//2-1):max(n-i,n//2+1)]
            rows.append(row)
        rowsI = []
        for i in range(m//2):
            row = gridI[i][min(i,n//2-1):max(n-i,n//2+1)]
            rowsI.append(row)
        rows = rows+rowsI[::-1]
        # print("ROWS", rows)

        cols = []
        for i in range(n//2):
            col = gridT[i][min(i,m//2-1):max(m-i,m//2+1)]
            cols.append(col)
        colsI = []
        for i in range(n//2):
            col = gridTI[i][min(i,m//2-1):max(m-i,m//2+1)]
            colsI.append(col)
        cols = cols+colsI[::-1]
        # print("COLS", cols)
        
        traversal = []
        for i in range(min(m//2,n//2)):
            curl = rows[i][:-1]+cols[-i-1][:-1]+rows[-i-1][::-1][:-1]+cols[i][::-1][:-1]
            traversal.append(curl)
        # print("traversal", traversal)
        traversal_new = []
        for trav in traversal:
            n = len(trav)
            moves = k%n
            trav_new = trav[moves:]+trav[:moves]
            traversal_new.append(trav_new)
        # print("traversal new", traversal_new)
        replacements = {}
        for curl_orig, curl_new in zip(traversal, traversal_new):
            for i, j in zip(curl_orig, curl_new):
                replacements[i] = j
        # print("replacements", replacements)

        m, n = len(grid), len(grid[0])
        grid_new = [[None for j in range(n)] for i in range(m)]
        for i in range(m):
            for j in range(n):
                pos_to_replace = replacements[i*n+j]
                k1, k2 = pos_to_replace//n, pos_to_replace%n
                grid_new[i][j] = grid_data[k1][k2]
        return grid_new

