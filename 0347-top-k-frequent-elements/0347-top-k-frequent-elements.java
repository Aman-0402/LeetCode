class Solution {
    public int[] topKFrequent(int[] nums, int k) {

        HashMap<Integer, Integer> freq = new HashMap<>();

        for (int num : nums)
            freq.put(num, freq.getOrDefault(num, 0) + 1);

        List<Integer>[] bucket = new ArrayList[nums.length + 1];

        for (int i = 0; i < bucket.length; i++)
            bucket[i] = new ArrayList<>();

        for (int num : freq.keySet()) {
            int count = freq.get(num);
            bucket[count].add(num);
        }

        int[] ans = new int[k];
        int index = 0;

        for (int i = bucket.length - 1; i >= 0 && index < k; i--) {
            for (int num : bucket[i]) {
                ans[index++] = num;
                if (index == k)
                    break;
            }
        }

        return ans;
    }
}