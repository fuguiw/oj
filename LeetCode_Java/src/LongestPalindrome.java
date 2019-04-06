import java.util.Arrays;

public class LongestPalindrome {
    public boolean longestPalindrome(String s, int[][] isPalindrome, int begin, int end) {
        if (isPalindrome[begin][end] == 1) {
            return true;
        }
        if (isPalindrome[begin][end] == -1) {
            return false;
        }

        boolean result = false;
        if (s.charAt(begin) == s.charAt(end)) {
            if (end - begin > 2)  {
                result = longestPalindrome(s, isPalindrome, begin + 1, end - 1);
            } else  {
                result = true;
            }
        }

        isPalindrome[begin][end] = result ? 1 : -1;
        return result;
    }

    public String longestPalindrome(String s) {
        int[][] isPalindrome = new int[s.length()][s.length()];

        String str = "";

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++){
                if (longestPalindrome(s, isPalindrome, i, j)) {
                    if (j - i + 1 > str.length()) {
                        str = s.substring(i, j + 1);
                    }
                }
            }
        }

        return str;
    }
}
