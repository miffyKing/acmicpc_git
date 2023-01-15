import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Boj_1520 {
        static int m;
        static int n;
        static List<Integer> x_dir = List.of(0,1, 0, -1);
        static List<Integer> y_dir = List.of(1,0, -1 ,0);
        static int table[][] = new int[501][501];
        static int dp[][] = new int[501][501];
        static boolean visited[][] = new boolean[501][501];

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        //int table[][] = new int[m+1][n+1];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                table[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dp[m-1][n-1] = 1;

        dfs(0,0);
        System.out.println(dp[0][0]);
        //DFS 시작
//        s.add(new Pair(0,0));
//        visited[0][0] = 1;
//
//        while (!s.isEmpty()) {
//            Pair cur = s.peek();
//            s.pop();
//
//            if (cur.x == m - 1 && cur.y == n - 1) {
//                cnt++;
//            }
//            for (int i = 0; i < 4; i++) {
//                int nx = cur.x + x_dir.get(i);
//                int ny = cur.y + y_dir.get(i);
//
//                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
//                if ((table[cur.x][cur.y] <= table[nx][ny])) continue;
//                s.add(new Pair(nx, ny));
//            }
//        }
//        System.out.println(cnt);
    }

    public static void dfs(int i, int j) {
        if (i == m - 1 && j == n - 1) {
            return;
        }
        if (visited[i][j]) {
            return ;
        }
        visited[i][j] = true;
        for (int dir = 0; dir < 4; dir++) {
            int nx = i + x_dir.get(dir);
            int ny = j + y_dir.get(dir);
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && table[nx][ny] < table[i][j]) {
                if (dp[nx][ny] != 0) {
                    dp[i][j] += dp[nx][ny];
                    continue;
                } else {
                    dfs(nx, ny);
                    dp[i][j] += dp[nx][ny];
                }
            }
        }


    }
    public static class Pair {
        int x, y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}

