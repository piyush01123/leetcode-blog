class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        H = {}
        for str in strs:
            strsorted = ''.join(sorted(str))
            if strsorted in H:
                H[strsorted].append(str)
                continue
            H[strsorted] = [str];
        return list(H.values())
