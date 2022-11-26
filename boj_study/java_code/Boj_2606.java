import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Vector;


class Pair {

    public int x;
    public int y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
    Pair() {

    }
}

public class Boj_2606 {

    private static int cnt = 0;
    static int [] vis = new int[102];
    static int [][] table;
    static private int n = 0;

    public static void main(String[] args) {

        //int n;
        int pair_num;

        Queue<Integer> q = new LinkedList<>();

        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        table = new int[n+1][n+1];
        pair_num = scanner.nextInt();

        for (int i = 0; i < pair_num; i++) {
            int tmp_x, tmp_y;
            tmp_x = scanner.nextInt();
            tmp_y = scanner.nextInt();

            table[tmp_x][tmp_y] = 1;
            table[tmp_y][tmp_x] = 1;
        }

        dfs(1);
        System.out.println(cnt - 1);
    }

    public static void dfs(int start) {
        vis[start] =1;
        cnt++;
        for (int i = 1; i <= n; i++) {
            if (table[start][i] == 1 && vis[i] != 1) {
                dfs(i);
            }
        }
    }
}

