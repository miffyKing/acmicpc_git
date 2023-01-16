import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Boj_1456 {

    public static void main(String[] args) {
        long n ,m;
        Scanner scanner = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(scanner.nextLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
//10^7 까지 소수 개수 세서 계속 제곱하면서 범위에 맞으면 리스트에 계속 넣는다
        List<Integer> primeList = new ArrayList<>();
        int table[] = new int[10000002];
        for (int i = 2; i <= 1000; i++) {
            int j = i;
            if (table[i] == 0) {
                primeList.add(i);
                for(j = 2; i * j <= 10000000; j++) {
                    table[i * j] = 1;
                }
            }
        }
    }

}
