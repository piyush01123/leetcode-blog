class Solution:
    def lengthLongestPath(self, input: str) -> int:
        paths = input.split('\n')
        path_lengths = {0: 0}
        maxlen = 0
        for path in paths:
            # name = path.strip()
            # depth = len(path)-len(name)
            depth = 0
            name = path
            while name[0]=='\t':
                name = name[1:]
                depth += 1
            # print(name, depth, path, path_lengths, '0', path[0], '0')
            if '.' in name:
                maxlen = max(maxlen, path_lengths[depth] + len(name))
            else:
                path_lengths[depth+1] = path_lengths[depth] + len(name) + 1
        return maxlen