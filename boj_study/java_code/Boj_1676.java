import java.util.Scanner;

public class Boj_1676 {
    public static void main(String[] args) {
        int n;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        int cnt2 =0;
        int cnt5 =0;
        for (int i = 1; i <= n; i++) {
            int number = i;
            while (number % 2 == 0) {
                if (number % 2 == 0)
                    cnt2++;
                number/=2;
            }
            while (number % 5 == 0) {
                if (i % 5 == 0)
                    cnt5++;
                number /= 5;
            }
        }
        System.out.println(Math.min(cnt2, cnt5));
    }
}
