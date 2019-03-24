import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class FourSumCount {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        Map<Integer, Integer> map = new HashMap<>();

        for (Integer a: A) {
            for (Integer b : B) {
                map.put(a + b, map.getOrDefault(a + b, 0) + 1);
            }
        }

        int count = 0;
        for (Integer c : C) {
            for (Integer d : D) {
                count += map.getOrDefault(-(c + d), 0);
            }
        }

        return count;
    }
}
