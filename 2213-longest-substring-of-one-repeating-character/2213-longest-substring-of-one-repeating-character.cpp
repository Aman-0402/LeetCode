class Solution {
    struct Node {
        char lc, rc;
        int leftLen, rightLen, best, len;

        Node() {
            lc = rc = 0;
            leftLen = rightLen = best = len = 0;
        }

        Node(char c) {
            lc = rc = c;
            leftLen = rightLen = best = len = 1;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;
        res.lc = a.lc;
        res.rc = b.rc;

        res.leftLen = a.leftLen;
        if (a.leftLen == a.len && a.rc == b.lc)
            res.leftLen = a.len + b.leftLen;

        res.rightLen = b.rightLen;
        if (b.rightLen == b.len && a.rc == b.lc)
            res.rightLen = b.len + a.rightLen;

        res.best = max(a.best, b.best);

        if (a.rc == b.lc)
            res.best = max(res.best, a.rightLen + b.leftLen);

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        this->s = s;

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};