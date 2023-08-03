import java.util.*;

public class Main {
    public static void main(String[] args) {
        Queue<Pair> q = new LinkedList();
        Scanner scanner = new Scanner(System.in);
        int n;
        int table[][] = new int[26][26];
        int visited[][] = new int[26][26];
        List<Integer> dir_X = List.of(1, 0, -1, 0);
        List<Integer> dir_y = List.of(0, 1, 0, -1);

        n = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();
            for (int j = 0; j < n; j++) {
                table[i][j] = Integer.parseInt(String.valueOf(s.charAt(j)));
            }
        }
        List<Integer> danji = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (table[i][j] != 0 && visited[i][j] != 1) {
                    //dfs START
                    int cnt = 0;
                    q.add(new Pair(i,j));

                    while (!q.isEmpty()) {
                        Pair cur = q.peek();
                        q.remove();

                        for (int dir = 0; dir < 4; dir++) {
                            int c_x = cur.x + dir_X.get(dir);
                            int c_y = cur.y + dir_y.get(dir);
                            if (c_x < 0 || c_y < 0 || c_x >= n || c_y >= n) continue;
                            if (table[c_x][c_y] != 1 || visited[c_x][c_y] == 1) continue;
                            visited[c_x][c_y] = 1;
                            q.add(new Pair(c_x, c_y));
                            cnt++;
                        }
                    }
                    danji.add(cnt);
                }
            }
        }

        System.out.println(danji.size());
        Collections.sort(danji);
        for (int i = 0; i < danji.size(); i++) {
            if (danji.get(i) == 0) {
                System.out.println(1);
                continue;
            }
            System.out.println(danji.get(i));
        }
    }

    public static class Pair {
        int x,y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }


}
