class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        for asteroid in asteroids:
            if mass<asteroid:
                return False
            if mass>=asteroids[-1]:
                return True
            mass+=asteroid
        return True