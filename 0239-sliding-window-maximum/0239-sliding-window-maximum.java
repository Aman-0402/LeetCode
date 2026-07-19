class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {

        Deque<Integer> dq = new ArrayDeque<>();
        int[] ans = new int[nums.length - k + 1];

        int index = 0;

        for (int i = 0; i < nums.length; i++) {

            while (!dq.isEmpty() && dq.peekFirst() <= i - k)
                dq.pollFirst();

            while (!dq.isEmpty() &&
                   nums[dq.peekLast()] < nums[i])
                dq.pollLast();

            dq.offerLast(i);

            if (i >= k - 1)
                ans[index++] = nums[dq.peekFirst()];
        }

        return ans;
    }
}