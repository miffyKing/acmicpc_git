import static java.lang.Math.min;

import java.util.Collection;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Boj_1149 {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n;
        int table[][] = new int[1002][1002];
        int dp[][] = new int[1002][3];

        n = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            String tmp = scanner.nextLine();
            StringTokenizer st = new StringTokenizer(tmp);
            int j = 0;
            while (st.hasMoreTokens()) {
                table[i][j] = Integer.parseInt(st.nextToken());
                j++;
            }
        }

        dp[0][0] = table[0][0];
        dp[0][1] = table[0][1];
        dp[0][2] = table[0][2];

        for (int i = 1; i < n; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + table[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + table[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + table[i][2];
        }
        List<Integer> candidates = List.of(dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]);
        System.out.println(Collections.min(candidates));
    }
}
