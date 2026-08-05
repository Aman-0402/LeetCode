class Solution {
public:
    void dfs(int u, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[u] = true;

        for (int v : graph[u]) {
            if (!vis[v])
                dfs(v, graph, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> graph(n);

        for (auto &e : invocations)
            graph[e[0]].push_back(e[1]);

        vector<bool> vis(n, false);

        dfs(k, graph, vis);

        for (auto &e : invocations) {
            if (!vis[e[0]] && vis[e[1]]) {

                vector<int> ans;

                for (int i = 0; i < n; i++)
                    ans.push_back(i);

                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++)
            if (!vis[i])
                ans.push_back(i);

        return ans;
    }
};