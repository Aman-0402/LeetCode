class Solution {
    public List<Integer> findAnagrams(String s, String p) {

        List<Integer> ans = new ArrayList<>();

        if (p.length() > s.length())
            return ans;

        int[] freqP = new int[26];
        int[] freqS = new int[26];

        for (char c : p.toCharArray())
            freqP[c - 'a']++;

        for (int i = 0; i < p.length(); i++)
            freqS[s.charAt(i) - 'a']++;

        if (Arrays.equals(freqP, freqS))
            ans.add(0);

        for (int i = p.length(); i < s.length(); i++) {

            freqS[s.charAt(i) - 'a']++;

            freqS[s.charAt(i - p.length()) - 'a']--;

            if (Arrays.equals(freqP, freqS))
                ans.add(i - p.length() + 1);
        }

        return ans;
    }
}