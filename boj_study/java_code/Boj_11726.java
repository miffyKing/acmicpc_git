import java.util.Scanner;

public class Boj_11726 {

    public static void main(String[] args) {
        int n;
        int table[] = new int[1002];
        Scanner scanner = new Scanner(System.in);
        n = Integer.parseInt(scanner.nextLine());

        table[1] = 1;
        table[2] = 2;
        table[3] = 3;
        for (int i = 4; i <= n; i++) {
            table[i] = (table[i-1] + table[i-2]) % 10007;
        }
        System.out.println(table[n]);
    }
}
