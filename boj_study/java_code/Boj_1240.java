import java.util.*;

public class Boj_1240 {

    public static void main(String[] args) {
        int n,m;
        Scanner scanner = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(scanner.nextLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        List<List<Pair>> table = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            table.add(new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            StringTokenizer st2 = new StringTokenizer(scanner.nextLine());
            int from = Integer.parseInt(st2.nextToken());
            int to = Integer.parseInt(st2.nextToken());
            int length = Integer.parseInt(st2.nextToken());
            table.get(from).add(new Pair(to, length));
            table.get(to).add(new Pair(from, length));
        }

        for (int tc = 0; tc < m; tc++) {
            StringTokenizer st3 = new StringTokenizer(scanner.nextLine());
            int from = Integer.parseInt(st3.nextToken());
            int to = Integer.parseInt(st3.nextToken());

            int visited[] = new int[1002];
            Queue<Integer> q = new LinkedList<>();

            q.add(from);
            visited[from] = 1;
            int total_leng = 0;
            while (!q.isEmpty()) {
                int cur = q.peek(); q.remove();
                for (int i = 0; i < table.get(cur).size(); i++) {
                    if (visited[table.get(cur).get(i).to] == 0) {
                        q.add(table.get(cur).get(i).to);
                        visited[table.get(cur).get(i).to] = visited[cur] + table.get(cur).get(i).length;
                    }
                }
            }
            System.out.println(visited[to]-1);

        }
    }

    public static class Pair {

        int to;
        int length;
        Pair(int a, int b) {
            this.to = a;
            this.length = b;
        }
    }
}
