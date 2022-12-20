import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class Boj_13265 {

    public static void main(String[] args) {
        int t;
        Scanner scanner = new Scanner(System.in);

        t = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < t; i++) {
            int visited[] = new int[1002];
            int color[] = new int[1002];
            Vector<Vector<Integer>> list = new Vector<Vector<Integer>>();
            StringTokenizer st= new StringTokenizer(scanner.nextLine());

            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            for (int j = 0; j <= n; j++) {
                list.add(new Vector<Integer>());
            }
            for (int j = 0; j < m; j++) {
                st = new StringTokenizer(scanner.nextLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                list.get(from).add(to);
                list.get(to).add(from);
            }
            boolean answer = true;

            Queue<Integer> q = new LinkedList<>();
            for (int j = 1; j <= n; j++) {
                if (visited[j] == 0) {
                    color[j] = 1; visited[j] = 1;
                    q.add(j);
                    while (!q.isEmpty()) {
                        int cur = q.peek(); q.remove();
                        for (int k = 0; k < list.get(cur).size(); k++) {
                            if (color[cur] == color[list.get(cur).get(k)]) {
                                answer = false;
                            }
                            if (visited[list.get(cur).get(k)] == 1 ) continue;
                            color[list.get(cur).get(k)] = 3 - color[cur];
                            q.add(list.get(cur).get(k));
                            visited[list.get(cur).get(k)] = 1;
                        }
                    }
                }
            }
            if (!answer) {
                System.out.println("impossible");
            } else {
                System.out.println("possible");
            }
        }
    }
}
