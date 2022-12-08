import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Boj_2468 {

    public static void main(String[] args) {
        int n;
        int table[][] = new int[102][102];
        //int visited[][] = new int[102][102];
        List<Integer> dir_x = List.of(0, 1, 0, -1);
        List<Integer> dir_y = List.of(1, 0, -1, 0);

        Scanner scanner = new Scanner(System.in);
        n = Integer.parseInt(scanner.nextLine());
        int max_height = 0;
        int min_height = 102;

        for (int i = 0; i < n; i++) {
            StringTokenizer stringTokenizer = new StringTokenizer(scanner.nextLine());
            for (int j = 0; j < n; j++) {
                table[i][j] = Integer.parseInt(stringTokenizer.nextToken());
                if (table[i][j] > max_height) {
                    max_height = table[i][j];
                }
                if (table[i][j] < min_height) {
                    min_height = table[i][j];
                }

            }
        }

        int max_val = 1;
        for (int height = min_height; height < max_height; height++) {

            int[][] visited = new int[102][102];
            int cnt = 0;
            Queue<Pair> q = new LinkedList<>();

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (table[i][j] - height > 0 && visited[i][j] == 0) {
                        q.add(new Pair(i,j));
                        visited[i][j] = 1;
                        cnt++;

                        while (!q.isEmpty()) {
                            Pair cur = q.peek();
                            q.remove();
                            //cnt++;
                            for (int dir = 0; dir < 4; dir++) {
                                int c_x = cur.x + dir_x.get(dir);
                                int c_y = cur.y + dir_y.get(dir);
                                if (c_x < 0 || c_x >= n || c_y < 0 || c_y >= n) continue;
                                if (table[c_x][c_y] - height <= 0 || visited[c_x][c_y] == 1) continue;
                                visited[c_x][c_y] = 1;
                                q.add(new Pair(c_x, c_y));
                            }
                        }
                    }
                }
            }
            if (cnt > max_val) {
                max_val = cnt;
            }

        }
        System.out.println(max_val);
    }

    public static class Pair {
        int x, y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }


}
