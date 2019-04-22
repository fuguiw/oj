public class DailyTemperatures {
    public int[] dailyTemperatures(int[] T) {
        int[] days = new int[T.length];
        int[] map = new int[101];

        for (int i = T.length - 1; i >= 0; i--) {
            map[T[i]] = i;

            days[i] = T.length;
            for (int j = T[i] + 1; j <= 100; j++) {
                if (map[j] > 0) {
                    days[i] = Math.min(days[i], map[j] - i);
                }
            }
            days[i] = days[i] == T.length ? 0 : days[i];
        }

        return days;
    }
}
