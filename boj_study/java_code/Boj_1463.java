import java.util.*;

import static java.lang.Math.min;

public class Boj_1463 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        int[] table = new int[1000002];
        table[1] = 0;
        table[2] = 1;
        table[3] = 1;
        for (int i = 4; i <= X; i++) {
            List<Integer> comp = new ArrayList<>();
            if (i % 2 == 0) {
                comp.add(table[i/2] + 1);
            }
            if (i % 3 == 0) {
                comp.add(table[i/3] + 1);
            }
            comp.add(table[i-1] + 1);
            Collections.sort(comp);
            table[i] = comp.get(0);
        }
        System.out.println(table[X]);
    }
}
