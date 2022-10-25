import java.util.Scanner;

// 클래스명 바꿔서 빨간줄 뜰 때 option + enter 하면 바꿀 수 있다.
public class Boj_11653 {
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        for (int i = 2; i <= n; i++) {
            inner:
            while (true) {
                if (n % i == 0) {
                    System.out.println(i);
                    n /= i;
                } else {
                    break inner;
                }
            }
        }



    }
}
