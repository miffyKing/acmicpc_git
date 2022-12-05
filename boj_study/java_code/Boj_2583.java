import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Boj_2583 {

    public static void main(String[] args) {
        int m,n,k;
        int table[][] = new int[102][102];                  //0으로 초기화 되어있나?

        Scanner scanner = new Scanner(System.in);
        StringTokenizer stringTokenizer = new StringTokenizer(scanner.nextLine());
        Queue<Pair> q = new LinkedList();
        List <Integer> dir_x = List.of(1, 0, -1, 0);
        List <Integer> dir_y = List.of(0, 1, 0, -1);

        m = Integer.parseInt(stringTokenizer.nextToken());
        n = Integer.parseInt(stringTokenizer.nextToken());
        k = Integer.parseInt(stringTokenizer.nextToken());

        for (int i = 0; i < k; i++) {
            stringTokenizer = new StringTokenizer(scanner.nextLine());
            int x1 = Integer.parseInt(stringTokenizer.nextToken());
            int y1 = Integer.parseInt(stringTokenizer.nextToken());
            int x2 = Integer.parseInt(stringTokenizer.nextToken());
            int y2 = Integer.parseInt(stringTokenizer.nextToken());

            for (int garo = y1; garo < y2; garo++) {
                for (int sero = x1; sero < x2; sero++) {
                    table[garo][sero] = 1;
                }
            }
        }
        int cnt = 0;
        ArrayList<Integer> width = new ArrayList<>();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (table[i][j] == 0) {
                    q.add(new Pair(i,j));
                    table[i][j] = 1;
                    int size_tmp = 0;
                    while (!q.isEmpty()) {
                        Pair cur = q.peek();
                        q.remove();
                        size_tmp++;
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = cur.x + dir_x.get(dir);
                            int ny = cur.y + dir_y.get(dir);
                            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if (table[nx][ny] == 1) continue;
                            table[nx][ny] = 1;
                            q.add(new Pair(nx, ny));
                        }
                    }
                    width.add(size_tmp);
                }
            }
        }
        Iterator iter = width.iterator();
        System.out.println(width.size());
        Collections.sort(width);
        int cur = 0;

        for (int i = 0; i < width.size(); i++) {
            System.out.print(width.get(i) + " ");
        }

        System.out.println();

    }

    public static class Pair {
        int x;
        int y;

        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
