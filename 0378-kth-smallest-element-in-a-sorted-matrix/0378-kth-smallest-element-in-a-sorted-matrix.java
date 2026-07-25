class Solution {
    public int kthSmallest(int[][] matrix, int k) {

        int n = matrix.length;

        PriorityQueue<int[]> minHeap = new PriorityQueue<>(
            (a, b) -> a[0] - b[0]
        );

        for (int i = 0; i < Math.min(n, k); i++) {
            minHeap.offer(new int[]{matrix[i][0], i, 0});
        }

        while (--k > 0) {

            int[] cur = minHeap.poll();

            int value = cur[0];
            int row = cur[1];
            int col = cur[2];

            if (col + 1 < n) {
                minHeap.offer(new int[]{
                    matrix[row][col + 1],
                    row,
                    col + 1
                });
            }
        }

        return minHeap.peek()[0];
    }
}