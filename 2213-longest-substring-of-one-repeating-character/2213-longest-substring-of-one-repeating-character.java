class Solution {

    class Node {
        char lc, rc;
        int leftLen, rightLen, best, len;

        Node() {
            len = 0;
        }

        Node(char c) {
            lc = rc = c;
            leftLen = rightLen = best = len = 1;
        }
    }

    Node[] tree;
    String s;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res = new Node();

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.leftLen = a.leftLen;

        if (a.leftLen == a.len && a.rc == b.lc) {
            res.leftLen = a.len + b.leftLen;
        }

        res.rightLen = b.rightLen;

        if (b.rightLen == b.len && a.rc == b.lc) {
            res.rightLen = b.len + a.rightLen;
        }

        res.best = Math.max(a.best, b.best);

        if (a.rc == b.lc) {
            res.best = Math.max(
                res.best,
                a.rightLen + b.leftLen
            );
        }

        return res;
    }

    void build(int node, int l, int r) {

        if (l == r) {
            tree[node] = new Node(s.charAt(l));
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    void update(int node, int l, int r,
                int idx, char c) {

        if (l == r) {
            tree[node] = new Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    public int[] longestRepeating(
            String s,
            String queryCharacters,
            int[] queryIndices) {

        this.s = s;

        int n = s.length();

        tree = new Node[4 * n + 5];

        build(1, 0, n - 1);

        int[] ans = new int[queryIndices.length];

        for (int i = 0; i < queryIndices.length; i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters.charAt(i)
            );

            ans[i] = tree[1].best;
        }

        return ans;
    }
}