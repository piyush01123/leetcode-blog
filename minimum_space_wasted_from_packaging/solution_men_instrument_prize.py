class Solution:
    def binarySearch(self, a, key):
        s,e = 0, len(a)-1
        while e>=s:
            m = (s+e)//2
            if a[m]==key:
                break
            elif a[m]>key:
                e=m-1
            else:
                s=m+1
        while m<len(a) and a[m]<=key:
            m += 1
        # print("m=",m)
        return m

    def minWastedSpace(self, packages: List[int], boxes: List[List[int]]) -> int:
        packages = sorted(packages)
        boxes = [sorted(boxCombo) for boxCombo in boxes]
        s = sum(packages)
        min_wastage = 1e10
        indicator = False
        for boxCombo in boxes:
            space_used = 0
            pos = 0
            if boxCombo[-1] < packages[-1]:
                continue
            for box in boxCombo:
                # new_pos = self.binarySearch(packages,box)
                new_pos = bisect.bisect(packages,box, pos)
                # print(box,new_pos)
                num_packages_with_this_box = new_pos-pos
                space_used += box * num_packages_with_this_box
                pos = new_pos
            wastage = space_used - s
            # print(boxCombo, wastage)
            if wastage<min_wastage:
                min_wastage = wastage
                indicator = True
        if not indicator:
            return -1
        return min_wastage  % (10**9 + 7) 