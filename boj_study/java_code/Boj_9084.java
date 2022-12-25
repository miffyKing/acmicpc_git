import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class Boj_9084 {

    public static void main(String[] args) {
        int t,n,m;
        Scanner scanner = new Scanner(System.in);

        t = Integer.parseInt(scanner.nextLine());
        for (int tc = 0; tc < t; tc++) {
            n = Integer.parseInt(scanner.nextLine());
            String tmp = scanner.nextLine();
            StringTokenizer st = new StringTokenizer(tmp);
            List<Integer> money = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                money.add(Integer.parseInt(st.nextToken()));
            }
            m = Integer.parseInt(scanner.nextLine());

            int[] dp = new int[m+1];
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                for (int j = money.get(i); j <= m; j++) {
                    dp[j] += dp[j - money.get(i)];
                }
            }
            System.out.println(dp[m]);
        }
    }


}
