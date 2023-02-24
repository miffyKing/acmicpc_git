import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Boj_1967 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static List<List<Edge>> adjList;
    static boolean[] isUsed;
    static int max = Integer.MIN_VALUE;
    static int dia = 0;

    static class Edge {
        int to;
        int weight;

        Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(br.readLine());
        if (N == 1)
        {
            System.out.println(0);
            return ;
        }
        //가중치를 둔 인접 리스트
        adjList = new ArrayList<>();
        for (int i = 0; i <= N; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int i = 1; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());
            int G = Integer.parseInt(st.nextToken());

            adjList.get(v1).add(new Edge(v2, G));
            adjList.get(v2).add(new Edge(v1, G));
        }
        isUsed = new boolean[N + 1];
        for (int i = 1; i <= N; i++){
            Arrays.fill(isUsed, false);
            dia = 0;
            dfs(i);
        }
        System.out.println(max);
    }

    private static void dfs(int x) {

        isUsed[x] = true;
        for (Edge e : adjList.get(x)) {
            int to = e.to;
            int weight = e.weight;
            if (!isUsed[to]) { // 연결되어있으면

                dia += weight;
                max = Math.max(max, dia);
                dfs(to);
                dia -= weight;
            }
        }
    }
}