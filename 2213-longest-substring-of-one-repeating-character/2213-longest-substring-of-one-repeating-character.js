var longestRepeating = function(s, queryCharacters, queryIndices) {

    const n = s.length;

    const tree = new Array(4 * n);

    function merge(a, b) {

        if (!a) return b;
        if (!b) return a;

        const lc = a[0];
        const rc = b[1];

        let leftLen = a[2];

        if (a[2] === a[5] && a[1] === b[0]) {
            leftLen = a[5] + b[2];
        }

        let rightLen = b[3];

        if (b[3] === b[5] && a[1] === b[0]) {
            rightLen = b[5] + a[3];
        }

        let best = Math.max(a[4], b[4]);

        if (a[1] === b[0]) {
            best = Math.max(
                best,
                a[3] + b[2]
            );
        }

        return [
            lc,
            rc,
            leftLen,
            rightLen,
            best,
            a[5] + b[5]
        ];
    }

    function build(node, l, r) {

        if (l === r) {
            const c = s[l];

            tree[node] = [
                c, c,
                1, 1,
                1, 1
            ];

            return;
        }

        const mid = Math.floor((l + r) / 2);

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    function update(node, l, r, idx, c) {

        if (l === r) {

            tree[node] = [
                c, c,
                1, 1,
                1, 1
            ];

            return;
        }

        const mid = Math.floor((l + r) / 2);

        if (idx <= mid) {
            update(node * 2, l, mid, idx, c);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1]
        );
    }

    build(1, 0, n - 1);

    const ans = [];

    for (let i = 0; i < queryIndices.length; i++) {

        update(
            1,
            0,
            n - 1,
            queryIndices[i],
            queryCharacters[i]
        );

        ans.push(tree[1][4]);
    }

    return ans;
};