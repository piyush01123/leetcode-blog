class Solution:
    def simplifyPath(self, path: str) -> str:
        res = []
        for level in path.split('/'):
            if not level or level == ".": continue
            if level == "..":
                if res: res.pop()
            else:
                res.append(level)
        return "/" + '/'.join(res)
