import java.util.*;

public class LongestIncreasingSequence {
    public static void main(String[] args) {
        int[][] matrix = generateMatrix(15, 15);

        System.out.println("Input Matrix:");
        printMatrix(matrix);

        int[][] dp = new int[15][15];
        int[][] prevX = new int[15][15];
        int[][] prevY = new int[15][15];
        int maxLength = 0;
        int endX = 0;
        int endY = 0;

        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                dp[i][j] = 1;
                prevX[i][j] = -1;
                prevY[i][j] = -1;

                for (int x = 0; x < i; x++) {
                    for (int y = 0; y < j; y++) {
                        if (matrix[x][y] < matrix[i][j] && dp[x][y] + 1 > dp[i][j]) {
                            dp[i][j] = dp[x][y] + 1;
                            prevX[i][j] = x;
                            prevY[i][j] = y;
                        }
                    }
                }

                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endX = i;
                    endY = j;
                }
            }
        }

        Stack<Integer> sequence = new Stack<>();
        int currentX = endX;
        int currentY = endY;

        while (currentX >= 0 && currentY >= 0) {
            sequence.push(matrix[currentX][currentY]);
            int tempX = prevX[currentX][currentY];
            currentY = prevY[currentX][currentY];
            currentX = tempX;
        }

        System.out.println("\nLongest Increasing Sequence:");
        while (!sequence.isEmpty()) {
            int num = sequence.pop();
            System.out.println(num + " (" + endX + "," + endY + ")");
            int tempX = prevX[endX][endY];
            endY = prevY[endX][endY];
            endX = tempX;
        }

        System.out.println("\nLength of the sequence: " + maxLength);
    }

    public static int[][] generateMatrix(int rows, int cols) {
        int[][] matrix = new int[rows][cols];
        Random random = new Random();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = random.nextInt(1001);
            }
        }

        return matrix;
    }

    public static void printMatrix(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}