import java.util.Arrays;

public class MaxIncreaseKeepingSkyline {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int[] rowSkyline = new int[grid.length];
        int[] colSkyline = new int[grid[0].length];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                rowSkyline[i] = Math.max(rowSkyline[i], grid[i][j]);
                colSkyline[j] = Math.max(colSkyline[j], grid[i][j]);
            }
        }

        int result = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                result += Math.min(rowSkyline[i], colSkyline[j]) - grid[i][j];
            }
        }
        return result;
    }
}
