class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows==1:
            return [[1]]
        if numRows==2:
            return [[1], [1,1]]
        triangle = [[1], [1,1]]
        for row_number in range(2,numRows):
            prev_row = triangle[row_number-1]
            row = [1]*(row_number+1)
            for i in range(1,row_number):
                row[i] = prev_row[i-1]+prev_row[i]
            triangle.append(row)
        return triangle