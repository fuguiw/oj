import java.util.Arrays;

public class ReverseWords {
    public String reverseWords(String s) {
        int begin = 0;
        int end = 0;
        char[] str = s.toCharArray();

        for ( ; end < str.length; end++) {
            if (begin != end && Character.isSpaceChar(str[end]) || end + 1 == str.length) {
                if (end + 1 == str.length) {
                    end++;
                }
                for (int i = 0; i < (end - begin) / 2; i++) {
                    char tmp = str[begin + i];
                    str[begin + i] = str[end - 1 - i];
                    str[end - 1 - i] = tmp;
                }
                begin = end + 1;
            } else if (begin == end && Character.isSpaceChar(str[begin])) {
                begin++;
            }
        }

        return new String(str);
    }
}
