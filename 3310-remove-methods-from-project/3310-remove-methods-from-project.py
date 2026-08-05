class Solution(object):
    def remainingMethods(self, n, k, invocations):

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
            if (not vis[u]) and vis[v]:
                return list(range(n))

        ans = []

        for i in range(n):
            if not vis[i]:
                ans.append(i)

        return ans