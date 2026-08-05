from typing import List

class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:

        graph = [[] for _ in range(n)]

        for u, v in invocations:
            graph[u].append(v)

        vis = [False] * n

        def dfs(u):
            vis[u] = True

            for v in graph[u]:
                if not vis[v]:
                    dfs(v)

        dfs(k)

        for u, v in invocations:
            if not vis[u] and vis[v]:
                return list(range(n))

        return [i for i in range(n) if not vis[i]]