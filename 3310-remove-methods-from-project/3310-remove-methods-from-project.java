import java.util.*;

class Solution {

    void dfs(int u, List<Integer>[] graph, boolean[] vis) {

        vis[u] = true;

        for (int v : graph[u])
            if (!vis[v])
                dfs(v, graph, vis);
    }

    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {

        List<Integer>[] graph = new ArrayList[n];

        for (int i = 0; i < n; i++)
            graph[i] = new ArrayList<>();

        for (int[] e : invocations)
            graph[e[0]].add(e[1]);

        boolean[] vis = new boolean[n];

        dfs(k, graph, vis);

        for (int[] e : invocations) {

            if (!vis[e[0]] && vis[e[1]]) {

                List<Integer> ans = new ArrayList<>();

                for (int i = 0; i < n; i++)
                    ans.add(i);

                return ans;
            }
        }

        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < n; i++)
            if (!vis[i])
                ans.add(i);

        return ans;
    }
}