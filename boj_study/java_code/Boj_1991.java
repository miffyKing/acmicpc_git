import java.util.*;
public class Boj_1991 {
    static List<Node> table = new ArrayList<>();
    public static void main(String[] args) {
        int n;
        Scanner scanner = new Scanner(System.in);
        n = Integer.parseInt(scanner.nextLine());


        for (int i = 0; i < n; i++) {
            String tmp = scanner.nextLine();
            StringTokenizer st= new StringTokenizer(tmp);
            int node = Integer.parseInt(st.nextToken());
            int lchild = Integer.parseInt(st.nextToken());
            int rchild = Integer.parseInt(st.nextToken());
            table.add(new Node(node, lchild, rchild));
        }
        preorder(0);
    }

    public static void preorder(int node) {
        
    }
    public static class Node{
        int cur;
        int lchild;
        int rchild;

        Node(int c, int l, int r) {
            cur = c;
            lchild = l;
            rchild = r;
        }
    }
}
