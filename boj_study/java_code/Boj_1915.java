import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Boj_1915 {

    public static void main(String[] args) throws IOException {
        int n, m;
        int[][] table = new int[1010][1010];
        int[][] dp = new int[1010][1010];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            String tmp = br.readLine();
            for (int j = 1; j <= m; j++) {
                if (tmp.charAt(j-1) == '0') {
                    table[i][j] = 0;
                } else {
                    flag = 1;
                    table[i][j] = 1;
                    dp[i][j] = 1;
                }
            }
        }

        dp[1][1] = table[1][1];
        List<Integer> all = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (dp[i - 1][j - 1] > 0 && dp[i - 1][j] > 0 && dp[i][j - 1] > 0 && dp[i][j] > 0) {
                    dp[i][j] = get_min(get_min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                    all.add(dp[i][j]);
                }
            }
        }
        all.add(1);
        Collections.sort(all);
        if (flag == 0) {
            System.out.println(0);
        } else {
            System.out.println(all.get(all.size()-1) * all.get(all.size()-1));

        }
    }

    public static int get_min(int a, int b) {
        if (a > b) {
            return b;
        } else {
            return a;
        }
    }
}
