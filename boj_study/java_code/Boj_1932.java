import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Boj_1932 {

    public static void main(String[] args) {
        int n;
        int table[][] = new int[502][502];
        int result[][] = new int[502][502];
        Scanner scanner = new Scanner(System.in);
        n = Integer.parseInt(scanner.nextLine());

        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(scanner.nextLine());
            int j = 1;
            while (st.hasMoreTokens()) {
                table[i][j] = Integer.parseInt(st.nextToken());
                j++;
            }
        }
        result[1][1] = table[1][1];
        result[2][1] = result[1][1] + table[2][1];
        result[2][2] = result[1][1] + table[2][2];
        for (int i = 3; i <= n; i++) {
            result[i][1] = result[i-1][1] + table[i][1];
            for (int j = 2; j < i; j++) {
                result[i][j] =Math.max(result[i-1][j-1], result[i-1][j]) + table[i][j];
            }
            result[i][i] = result[i-1][i-1] + table[i][i];
        }
        List<Integer> hoobo = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            hoobo.add(result[n][i]);
        }
        System.out.println(Collections.max(hoobo));
    }
}
