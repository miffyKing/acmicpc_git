import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Boj_2240 {

    public static void main(String[] args) {
        int table[][][] = new int[3][1002][32];
        int arr[] = new int[1002];
        Scanner scanner = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(scanner.nextLine());
        int t,w;
        t = Integer.parseInt(st.nextToken());
        w = Integer.parseInt(st.nextToken());
        for (int i = 1; i <= t; i++) {
            arr[i] = Integer.parseInt(scanner.nextLine());
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i <= t; i++) {
            for (int j = 1; j <= w+1; j++) {
                if (arr[i] == 1) {
                    table[1][i][j] = Integer.max(table[1][i - 1][j] + 1, table[2][i - 1][j - 1] + 1);
                    table[2][i][j] = Integer.max(table[1][i - 1][j - 1], table[2][i - 1][j]);
                    ans.add(table[1][i][j]);
                    ans.add(table[2][i][j]);
                } else {
                    if (i == 1 && j == 1) {
                        continue;
                    }
                    table[1][i][j] = Integer.max(table[1][i-1][j], table[2][i-1][j-1]);
                    table[2][i][j] = Integer.max(table[1][i-1][j-1] + 1, table[2][i-1][j] + 1);
                    ans.add(table[1][i][j]);
                    ans.add(table[2][i][j]);
                }
            }
        }
        Collections.sort(ans);
        System.out.println(ans.get(ans.size() - 1));
    }
}
