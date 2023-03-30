class Solution:
    def minWastedSpace(self, A, boxes):
        A.sort()
        res = float('inf')
        for B in boxes:
            B.sort()
            if B[-1] < A[-1]: continue
            cur = i = 0
            for b in B:
                j = bisect.bisect(A, b, i)
                cur += b * (j - i)
                i = j
            res = min(res, cur)
        return (res - sum(A)) % (10**9 + 7) if res < float('inf') else -1
    
#     def binarySearchSmaller(self, a, key):
#         if key<a[0]: return -1
#         s,e = 0, len(a)-1
#         while e>=s:
#             m = (s+e)//2
#             if a[m]==key:
#                 return key
#             elif a[m]>key:
#                 e=m-1
#             else:
#                 s=m+1
#         if a[m]<key:
#             return a[m]
#         else:
#             return a[m-1]

#     def minWastedSpace(self, packages: List[int], boxes: List[List[int]]) -> int:
#         packages = sorted(packages)
#         box_sizes = set([b for box in boxes for b in box])
#         packaging = {k: [] for k in box_sizes}
#         for box_size in box_sizes:
#             packaging[box_size].append(self.binarySearchSmaller(packages, box_size))
#         print(packaging)
#         return -1

    
# class Solution:
#     def binarySearchLarger(self, a, key):
#         s,e = 0, len(a)-1
#         while e>=s:
#             m = (s+e)//2
#             if a[m]==key:
#                 return key
#             elif a[m]>key:
#                 e=m-1
#             else:
#                 s=m+1
#         if a[m]>key:
#             return a[m]
#         else:
#             return a[m+1]

#     def minWastedSpace(self, packages: List[int], boxes: List[List[int]]) -> int:
#         wastages = []
#         for boxComb  in boxes:
#             if max(packages)>max(boxComb):
#                 continue
#             boxComb = sorted(boxComb)
#             wastage = 0
#             for item in packages:
#                 opt_box = self.binarySearchLarger(boxComb, item)
#                 wastage += opt_box-item
#             wastages.append(wastage)
#         if len(wastages)==0: return -1
#         return min(wastages)
    
        