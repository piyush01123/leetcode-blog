class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        L = itertools.permutations(digits,3)
        # print(digits, set(list(L)))
        # return []
        res = []
        for item in set(list(L)):
            a,b,c = item
            num = 100*a + 10*b + c
            if num%2==0 and num>=100:
                res.append(num)
        return sorted(res)