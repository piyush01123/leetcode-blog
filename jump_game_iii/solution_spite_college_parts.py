class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        if arr[start]==0: return True
        targets = []
        n = len(arr)
        graph = {i: [] for i in range(n)}
        for i in range(n):
            if arr[i]==0:
                targets.append(i)
            else:
                if 0 <= i-arr[i] < n:
                    graph[i].append(i-arr[i])
                if 0 <= i+arr[i] < n:
                    graph[i].append(i+arr[i])
        print(graph,targets)
        visited = [False for _ in range(n)]
        visited[start] = True
        queue = [start]
        while len(queue)>0:
            s = queue.pop(0)
            for nbd in graph[s]:
                if not visited[nbd]:
                    if nbd in targets:
                        return True
                    visited[nbd] = True
                    queue.append(nbd)
        return False
        
