import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Boj_6593 {

    public static void main(String[] args) {


        Scanner scanner = new Scanner(System.in);
        while(true) {
            int l,r,c;
            Queue<Coor> q = new LinkedList<>();
            int table[][][] = new int[32][32][32];
            int visited[][][]= new int[32][32][32];
            List<Integer> dir_x = List.of(1, -1, 0, 0, 0, 0);
            List<Integer> dir_y = List.of(0, 0, 1, -1, 0, 0);
            List<Integer> dir_z = List.of(0, 0, 0, 0, 1, -1);
            String input = scanner.nextLine();
            if (input.contains("0 0 0"))
                break;

            StringTokenizer stringTokenizer = new StringTokenizer(input);
            //System.out.println("input is   " + input);
            l = Integer.parseInt(stringTokenizer.nextToken());
            r = Integer.parseInt(stringTokenizer.nextToken());
            c = Integer.parseInt(stringTokenizer.nextToken());

            Coor out = null;
            for (int height = 0; height < l; height++) {
                for (int sero = 0; sero < r; sero++) {
                    String line = scanner.nextLine();
                    for (int garo = 0; garo < c; garo++) {
                        if (line.charAt(garo) == 'S') {
                            q.add(new Coor(sero, garo, height));
                            table[sero][garo][height] = 1;
                            visited[sero][garo][height] = 0;
                            //q 삽입
                        } else if (line.charAt(garo) == '.') {
                            table[sero][garo][height] = 0;
                        } else if (line.charAt(garo) == '#') {
                            table[sero][garo][height] = 1;
                        } else if (line.charAt(garo) == 'E') {
                            table[sero][garo][height] = 0;
                            out = new Coor(sero, garo, height);
                            //출구 조건.
                        }
                    }
                }
                if (height < l) {
                    String blankLine = scanner.nextLine();

                }
            }

            int cnt = 0;

            while (!q.isEmpty()) {
                Coor cur = q.peek();
                q.remove();

                for (int i = 0; i < 6; i++) {
                    int d_x = dir_x.get(i) + cur.x;
                    int d_y = dir_y.get(i) + cur.y;
                    int d_z = dir_z.get(i) + cur.z;
                    if (d_x < 0 || d_x >= r || d_y < 0 || d_y >= c || d_z < 0 || d_z >= l) continue;
                    if (visited[d_x][d_y][d_z] != 0 || table[d_x][d_y][d_z] == 1) continue;
                    visited[d_x][d_y][d_z] = visited[cur.x][cur.y][cur.z] + 1;
                    q.add(new Coor(d_x, d_y, d_z));
                }
            }

            if (visited[out.x][out.y][out.z] != 0) {
                System.out.println("Escaped in " + visited[out.x][out.y][out.z] + " minute(s).");
            } else {
                System.out.println("Trapped!");
            }
        }

    }

    public static class Coor {
        int x, y, z;

        Coor(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

}
