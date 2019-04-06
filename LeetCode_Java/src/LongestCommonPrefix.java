public class LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }

        int result = strs[0].length();
        for (String str : strs) {
            result = Math.min(result, str.length());
            for (int i = 0; i < str.length() && i < result; i++) {
                if (str.charAt(i) != strs[0].charAt(i)) {
                    result = i;
                    break;
                }
            }
        }

        return strs[0].substring(0, result);
    }
}
