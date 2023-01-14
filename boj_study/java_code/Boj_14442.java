import java.io.*;
import java.util.*;

public class Boj_14442 {
    static class Pair {
        int x;
        int y;
        int chance;         //벽 부수기 찬스를 썼는지 안썼는지
        int cnt;
        public Pair(int x, int y, int chance, int cnt) {
            this.x = x;
            this.y = y;
            this.chance=  chance;
            this.cnt = cnt;
        }
    }
    public static void main(String[] args) throws IOException {


        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] inputs = bf.readLine().split(" "); //토크나이저 안쓰고 바로 분리가능 했네

        int n = Integer.parseInt(inputs[0]);
        int m = Integer.parseInt(inputs[1]);
        int k = Integer.parseInt(inputs[2]);

        char table[][] = new char[n][m];

        for (int i = 0; i < n; i++) {
            String tmp = bf.readLine();
            for (int j = 0; j < m; j++) {
                table[i][j] = tmp.charAt(j);
            }
        }
        System.out.println(dfsFunc(table, n, m, k));
        return;
    }

    public static int dfsFunc(char[][] table, int n, int m, int k) {
        boolean visited[][][] = new boolean[n][m][12];
        Deque<Pair> q = new LinkedList<>();
        List<Integer> dir_y = List.of(1,0,-1,0);
        List<Integer> dir_x = List.of(0,1,0,-1);

        q.add(new Pair(0,0,0, 1));

        while (!q.isEmpty()) {
            Pair cur = q.poll();

            if (cur.x == n-1 && cur.y == m-1) {
                //System.out.println(cur.cnt);
                return cur.cnt;
            }

            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.x + dir_x.get(dir);
                int ny = cur.y + dir_y.get(dir);

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;   //범위 벗어난 경우
                int nxt_cnt = cur.cnt+1;

                if (table[nx][ny] == '0'){  // 벽이 아닌 경우
                    if (!visited[nx][ny][cur.chance]) {   //벽을 지금까지 안부섰고, 방문한적이 없다.
                        q.offer(new Pair(nx,ny, cur.chance, nxt_cnt));
                        visited[nx][ny][cur.chance] = true;
                    }
                } else if (table[nx][ny] == '1') {  //벽인 경우
                    if (cur.chance < k && !visited[nx][ny][cur.chance+1]) {  // 아직 한번도 안부섰으면 부수고 들어감.
                        q.offer(new Pair(nx,ny, cur.chance+1, nxt_cnt));
                        visited[nx][ny][cur.chance+1] = true;
                    }
                }
            }
        }

        return -1;
    }
}

