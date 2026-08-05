#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int to;
    struct Node *next;
} Node;

void dfs(int u, Node **graph, bool *vis) {
    vis[u] = true;

    for (Node *cur = graph[u]; cur != NULL; cur = cur->next) {
        if (!vis[cur->to])
            dfs(cur->to, graph, vis);
    }
}

int* remainingMethods(int n, int k,
                      int** invocations,
                      int invocationsSize,
                      int* invocationsColSize,
                      int* returnSize) {

    Node **graph = (Node **)calloc(n, sizeof(Node*));

    for (int i = 0; i < invocationsSize; i++) {

        int u = invocations[i][0];
        int v = invocations[i][1];

        Node *node = (Node *)malloc(sizeof(Node));
        node->to = v;
        node->next = graph[u];
        graph[u] = node;
    }

    bool *vis = (bool *)calloc(n, sizeof(bool));

    dfs(k, graph, vis);

    for (int i = 0; i < invocationsSize; i++) {

        int u = invocations[i][0];
        int v = invocations[i][1];

        if (!vis[u] && vis[v]) {

            int *ans = (int *)malloc(n * sizeof(int));

            for (int j = 0; j < n; j++)
                ans[j] = j;

            *returnSize = n;

            // Free memory
            for (int j = 0; j < n; j++) {
                Node *cur = graph[j];
                while (cur) {
                    Node *tmp = cur;
                    cur = cur->next;
                    free(tmp);
                }
            }

            free(graph);
            free(vis);

            return ans;
        }
    }

    int *ans = (int *)malloc(n *sizeof(int));

    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (!vis[i])
            ans[idx++] = i;
    }

    *returnSize = idx;

    // Free memory
    for (int j = 0; j < n; j++) {
        Node *cur = graph[j];
        while (cur) {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }

    free(graph);
    free(vis);

    return ans;
}