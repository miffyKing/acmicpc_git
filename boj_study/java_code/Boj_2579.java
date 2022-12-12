import static java.lang.Math.max;

import java.util.Scanner;

public class Boj_2579 {

    public static void main(String[] args) {
        int stair[] = new int[303];
        int table[][] = new int[303][2];
        Scanner scanner = new Scanner(System.in);
        int n = Integer.parseInt(scanner.nextLine());
        for (int i = 1; i <= n; i++) {
            int input = Integer.parseInt(scanner.nextLine());
            stair[i] = input;
        }
        table[1][0] = stair[1];
        table[1][1] = stair[1];
        table[2][0] = table[1][0] + stair[2];
        table[2][1] = stair[2];
        for (int i = 3; i <= n; i++) {
            table[i][0] = table[i - 1][1] + stair[i];
            table[i][1] = max(table[i - 2][0], table[i - 2][1]) + stair[i];
        }
        System.out.println(max(table[n][0], table[n][1]));
    }
}
