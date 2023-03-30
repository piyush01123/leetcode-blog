class Solution:
    def minWastedSpace(self, packages: List[int], boxes: List[List[int]]) -> int:
        packages = sorted(packages)
        boxes = [sorted(boxComb) for boxComb in boxes]
        s = sum(packages)
        min_wastage = 1e10
        indicator = False
        for boxComb in boxes:
            if boxComb[-1] < packages[-1]:
                continue
            space_used = 0
            pos = 0
            for box in boxComb:
                new_pos = bisect.bisect(packages,box,pos)
                # print(box,new_pos)
                num_packages_with_this_box = new_pos-pos
                space_used += box * num_packages_with_this_box
                pos = new_pos
            wastage = space_used - s
            print(wastage)
            if wastage<min_wastage:
                min_wastage = wastage
                indicator = True
        if not indicator:
            return -1
        return min_wastage  % (10**9 + 7) 