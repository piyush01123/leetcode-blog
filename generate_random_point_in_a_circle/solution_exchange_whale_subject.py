class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.r, self.cx, self.cy = radius, x_center, y_center

    def randPoint(self) -> List[float]:
        theta = uniform(0,2*pi)
        r = self.r * sqrt(uniform(0,1))
        x, y = r*cos(theta), r*sin(theta)
        return [self.cx+x, self.cy+y]


# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()