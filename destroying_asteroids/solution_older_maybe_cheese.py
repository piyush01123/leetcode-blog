class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        while len(asteroids)>0:
            if asteroids[-1]<=mass:
                return True
            index = bisect.bisect_left(asteroids,mass)
            if index==0 and asteroids[index]>mass:
                return False
            if index>0 and (asteroids[index]>mass):
                index-=1
            mass+=asteroids.pop(index)
        return True

        