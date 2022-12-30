import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Boj_1194 {

    public static void main(String[] args) {
        int n, k;
        Scanner scanner = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(scanner.nextLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        List<Integer> money = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            money.add(Integer.parseInt(scanner.nextLine()));
        }
        Collections.sort(money);
        int dp[] = new int[k+1];
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = money.get(i); j <= k; j++) {
                dp[j] += dp[j - money.get(i)];
                if (j == k) {

                }
            }
        }


    }
}
