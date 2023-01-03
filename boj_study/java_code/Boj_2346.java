import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Boj_2346 {

    public static void main(String[] args) {
        int n;
        LinkedList<Pair> balloons = new LinkedList<>();
        Scanner scanner = new Scanner(System.in);
        n = Integer.parseInt(scanner.nextLine());
        StringTokenizer st = new StringTokenizer(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            balloons.add(new Pair(i+1, Integer.parseInt(st.nextToken())));
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            int steps = balloons.get(cur).y;
            System.out.println("stemps : " + steps);
            System.out.println(balloons.get(cur).x);
            //balloons.remove(cur);
            int bef_cur = cur;
            if (steps < 0) {
                System.out.println("!!");
                if (cur - steps < 0) {
                    cur = (balloons.size() + (cur - steps)) % (balloons.size());
                } else {
                    cur = (cur + steps) % (balloons.size());
                }
            } else {
                System.out.println("??");
                cur = (cur + steps)% (balloons.size());
            }
            balloons.remove(bef_cur);
        }

    }

    public static class Pair {
        int x; int y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

}
