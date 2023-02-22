import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int n;
        long table[] = new long[92];
        Scanner scanner = new Scanner(System.in);
        n = Integer.parseInt(scanner.nextLine());

        table[1] = 1;
        table[2] = 1;
        table[3] = 2;
        table[4] = 3;
        table[5] = 5;
        table[6] = 8;
        for (int i = 7; i <= n; i++) {
            table[i] = table[i-1] + table[i-2];
        }
        System.out.println(table[n]);
    }

}

