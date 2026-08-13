#include <stdlib.h>
#include <string.h>

typedef struct {
    char leftChar;
    char rightChar;

    int leftLen;
    int rightLen;

    int best;
    int len;
} Node;

Node *tree;
char *str;

Node merge(Node a, Node b) {

    Node res;

    res.len = a.len + b.len;

    res.leftChar = a.leftChar;
    res.rightChar = b.rightChar;

    res.leftLen = a.leftLen;

    if (a.leftLen == a.len &&
        a.rightChar == b.leftChar) {

        res.leftLen = a.len + b.leftLen;
    }

    res.rightLen = b.rightLen;

    if (b.rightLen == b.len &&
        a.rightChar == b.leftChar) {

        res.rightLen = b.len + a.rightLen;
    }

    res.best = a.best > b.best
               ? a.best
               : b.best;

    if (a.rightChar == b.leftChar) {

        int combined =
            a.rightLen + b.leftLen;

        if (combined > res.best)
            res.best = combined;
    }

    return res;
}

void build(int node, int l, int r) {

    if (l == r) {

        tree[node].leftChar = str[l];
        tree[node].rightChar = str[l];

        tree[node].leftLen = 1;
        tree[node].rightLen = 1;

        tree[node].best = 1;
        tree[node].len = 1;

        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    tree[node] =
        merge(tree[node * 2],
              tree[node * 2 + 1]);
}

void update(int node, int l, int r,
            int idx, char c) {

    if (l == r) {

        tree[node].leftChar = c;
        tree[node].rightChar = c;

        tree[node].leftLen = 1;
        tree[node].rightLen = 1;

        tree[node].best = 1;
        tree[node].len = 1;

        return;
    }

    int mid = (l + r) / 2;

    if (idx <= mid) {

        update(node * 2,
               l,
               mid,
               idx,
               c);

    } else {

        update(node * 2 + 1,
               mid + 1,
               r,
               idx,
               c);
    }

    tree[node] =
        merge(tree[node * 2],
              tree[node * 2 + 1]);
}

/*
 * LeetCode C interface may vary depending on
 * the platform's generated signature.
 *
 * Core function:
 */
int* longestRepeating(
    char* s,
    char* queryCharacters,
    int* queryIndices,
    int queryIndicesSize,
    int* returnSize) {

    int n = strlen(s);

    str = s;

    tree = (Node*)calloc(
        4 * n + 5,
        sizeof(Node)
    );

    build(1, 0, n - 1);

    int* ans = (int*)malloc(
        queryIndicesSize * sizeof(int)
    );

    for (int i = 0;
         i < queryIndicesSize;
         i++) {

        update(
            1,
            0,
            n - 1,
            queryIndices[i],
            queryCharacters[i]
        );

        ans[i] = tree[1].best;
    }

    *returnSize = queryIndicesSize;

    free(tree);

    return ans;
}