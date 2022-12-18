import java.util.Scanner;

public class Boj_1003 {

    public static void main(String[] args) {
        int t;
        int fibo[][] = new int[42][3];

        fibo[0][0] = 1;
        fibo[0][1] = 0;

        fibo[1][0] = 0;
        fibo[1][1] = 1;

        fibo[2][0] = 1;
        fibo[2][1] = 1;

        fibo[3][0] = fibo[2][0] + fibo[1][0];
        fibo[3][1] = fibo[2][1] + fibo[1][1];

        Scanner scanner = new Scanner(System.in);


        t = Integer.parseInt(scanner.nextLine());
        for (int i = 4; i <= 40; i++) {
            fibo[i][0] = fibo[i-1][0] + fibo[i-2][0];
            fibo[i][1] = fibo[i-1][1] + fibo[i-2][1];
        }
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(scanner.nextLine());
            System.out.println(fibo[n][0] + " " + fibo[n][1]);
        }
    }
}
