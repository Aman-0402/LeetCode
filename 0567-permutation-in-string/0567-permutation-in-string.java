class Solution {
    public boolean checkInclusion(String s1, String s2) {

        if (s1.length() > s2.length())
            return false;

        int[] freq1 = new int[26];
        int[] freq2 = new int[26];

        for (char c : s1.toCharArray())
            freq1[c - 'a']++;

        for (int i = 0; i < s1.length(); i++)
            freq2[s2.charAt(i) - 'a']++;

        if (java.util.Arrays.equals(freq1, freq2))
            return true;

        for (int i = s1.length(); i < s2.length(); i++) {

            freq2[s2.charAt(i) - 'a']++;

            freq2[s2.charAt(i - s1.length()) - 'a']--;

            if (java.util.Arrays.equals(freq1, freq2))
                return true;
        }

        return false;
    }
}