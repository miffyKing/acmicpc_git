import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class Boj_15723 {
    static Vector<Vector<Integer>> table = new Vector<Vector<Integer>>();
    public static void main(String[] args) {
        int n;
        Scanner scanner = new Scanner(System.in);
        n = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i <= 26; i++) {
            table.add(new Vector<Integer>());
        }
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(scanner.nextLine());
            int from = st.nextToken().charAt(0);
            st.nextToken();
            int to = st.nextToken().charAt(0);
            table.get(from - 'a').add(to - 'a');
        }
        int m = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(scanner.nextLine());
            int from = st.nextToken().charAt(0);
            st.nextToken();
            int to =st.nextToken().charAt(0);

            if (dfs(from - 'a', to - 'a') == true) {
                System.out.println("T");
            } else {
                System.out.println("F");
            }
        }
    }

    public static boolean dfs(int from, int target) {
        int visited[] = new int[26];
        Queue<Integer> q = new LinkedList<>();

        q.add(from);
        visited[from] = 1;
        while(!q.isEmpty()) {
            int cur = q.peek();
            q.remove();
            for (int i = 0; i < table.get(cur).size(); i++) {
                int cur_view = table.get(cur).get(i);
                if (cur_view == target) {
                    return true;
                }
                if (visited[cur_view] == 1) continue;
                visited[cur_view] = 1;
                q.add(cur_view);
            }
        }
        return false;
    }
}
