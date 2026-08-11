class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rowsize = matrix[0].length;
        int colsize = matrix.length;

        for (int i = 0; i < colsize; i++) {
            for (int j = 0; j < rowsize; j++) {
                if (matrix[i][j] == target)
                    return true;
            }
        }

        return false;
    }
}