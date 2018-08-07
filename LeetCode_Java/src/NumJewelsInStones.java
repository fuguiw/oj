import java.util.HashSet;
import java.util.Set;

public class NumJewelsInStones
{
    public int numJewelsInStones(String J, String S) {
        Set<Character> jewels = new HashSet<>();
        for (int i = 0; i < J.length(); i++) {
            jewels.add(J.charAt(i));
        }

        int result = 0;
        for (int i = 0; i < S.length(); i++) {
            if (jewels.contains(S.charAt(i))) {
                result++;
            }
        }

        return result;
    }
}
