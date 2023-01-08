import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Boj_1012 {

    public static void main(String[] args) {
        int t,m,n,k;
        Scanner scanner = new Scanner(System.in);
        t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            List<Integer> x_dir = List.of(1, 0, -1, 0);
            List<Integer> y_dir = List.of(0, 1, 0, -1);
            m = scanner.nextInt();
            n = scanner.nextInt();
            k = scanner.nextInt();
            int[][] table = new int[50][50];
            int[][] visited = new int[50][50];
            Queue<Pair> q = new LinkedList<>();
            int cnt = 0;

            for (int j = 0; j < k; j++) {
                int tmp1 = scanner.nextInt();
                int tmp2 = scanner.nextInt();
                table[tmp1][tmp2] = 1;
            }

            //dfs 시작
            for (int garo = 0; garo < m; garo++) {
                for (int sero = 0; sero < n; sero++) {
                    if (table[garo][sero] == 1 && visited[garo][sero] == 0) {
                        cnt++;
                        q.add(new Pair(garo, sero));
                        visited[garo][sero] = 1;
                        //cnt++;
                        while (!q.isEmpty()) {
                            Pair cur = q.peek();
                            q.remove();
                            for (int dir = 0; dir < 4; dir++) {
                                int nx = cur.x + x_dir.get(dir);
                                int ny = cur.y + y_dir.get(dir);
                                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                                if (visited[nx][ny] == 1 || table[nx][ny] != 1) continue;
                                visited[nx][ny]  = 1;
                                q.add(new Pair(nx, ny));
                            }
                        }
                    }
                }
            }
            System.out.println(cnt);
        }



    }

    public static class Pair {
        int x,y;

        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }

    }
}
