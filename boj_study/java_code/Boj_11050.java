import java.util.Scanner;

public class Boj_11050 {
    public static void main(String[] args) {
        int n,k;
        int arr[][] = new int[11][11];
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        k = scanner.nextInt();
        arr[0][0] = 1;
        arr[1][0] = 1;
        arr[1][1] = 1;
        for (int i = 2; i <= 10; i++) {
            for (int j = 1; j <= i-1; j++) {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
            arr[i][0] = 1;
            arr[i][i] = 1;
        }
        System.out.println(arr[n][k]);
    }
}
