class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        H = collections.defaultdict(list)
        res = []
        for dir in paths:
            dirparts = dir.split(' ')
            dirpath, files = dirparts[0],dirparts[1:]
            for file in files:
                filename, content = file[:-1].rsplit('(')
                filefullpath = dirpath+'/'+filename
                H[content].append(filefullpath)
        for content,filepaths in H.items():
            if len(filepaths)<2:
                continue
            res.append(filepaths)
        return res