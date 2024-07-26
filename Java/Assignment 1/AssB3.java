import java.util.*;

public class AssB3 
{
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) 
    {
        while (true) 
        {
            System.out.println("\n1. Add matrices\n2. Transpose matrix\n3. Exit");
            System.out.print("Choose an option: ");
            int choice = scanner.nextInt();

            if (choice == 1) 
            {
                addMatrices();
            } 
            else if (choice == 2) 
            {
                transposeMatrix();
            } 
            else if (choice == 3) 
            {
                System.out.println("Exiting...");
                break;
            } 
            else 
            {
                System.out.println("Invalid choice!");
            }
        }
    }

    static void addMatrices() 
    {
        int[][] a = inputMatrix("first");
        int[][] b = inputMatrix("second");
        if (a.length != b.length || a[0].length != b[0].length) 
        {
            System.out.println("Matrices must have the same dimensions!");
            return;
        }
        int[][] result = new int[a.length][a[0].length];
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                result[i][j] = a[i][j] + b[i][j];
        printMatrix(result);
    }

    static void transposeMatrix() 
    {
        int[][] a = inputMatrix("original");
        int[][] result = new int[a[0].length][a.length];
        for (int i = 0; i < a.length; i++)
            for (int j = 0; j < a[0].length; j++)
                result[j][i] = a[i][j];
        printMatrix(result);
    }

    static int[][] inputMatrix(String label) 
    {
        System.out.print("Enter rows and columns for " + label + " matrix: ");
        int r = scanner.nextInt(), c = scanner.nextInt();
        int[][] matrix = new int[r][c];
        System.out.println("Enter matrix elements:");
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                matrix[i][j] = scanner.nextInt();
        return matrix;
    }

    static void printMatrix(int[][] matrix) 
    {
        for (int[] row : matrix) {
            for (int el : row) System.out.print(el + " ");
            System.out.println();
        }
    }
}

