class Solution {
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];

        int num = 1;
        for (int i = 0; i <= (n - 1) / 2; i++) {
            for (int j = i; j < n - i; j++) {
                matrix[i][j] = num++;
            }
            for (int j = i + 1; j < n - i; j++) {
                matrix[j][n - i - 1] = num++;
            }
            for (int j = n - i - 2; j >= i; j--) {
                matrix[n - 1 - i][j] = num++;
            }
            for (int j = n - i - 2; j > i; j--) {
                matrix[j][i] = num++;
            }
        }

        return matrix;
    }
}