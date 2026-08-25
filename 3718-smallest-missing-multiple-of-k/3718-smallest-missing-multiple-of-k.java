class Solution {
    public int missingMultiple(int[] nums, int k) {
        HashSet<Integer> seen = new HashSet<>();

        for (int num : nums) {
            seen.add(num);
        }

        int multiple = k;

        while (seen.contains(multiple)) {
            multiple += k;
        }

        return multiple;
    }
}