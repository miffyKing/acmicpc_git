import java.util.Scanner;

public class Boj_1929 {
    public static void main(String[] args) {
        int m, n;
        int[] arr = new int[1000001];

        Scanner scanner = new Scanner(System.in);
        m = scanner.nextInt();
        n = scanner.nextInt();

        for (int i = 2; i <= n; i++) {
            for (int j = 2; i * j <= n; j++) {
                arr[i*j] = 1;
            }
        }
        arr[1] = 1;
        for (int i = m; i <= n; i++) {
            if (arr[i] == 0) {
                System.out.println(i);
            }
        }
    }
}
