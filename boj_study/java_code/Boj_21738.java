import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Vector;

public class Boj_21738 {

    static int n, s, p;
    static Scanner scanner = new Scanner(System.in);
    static Vector<Vector<Integer>> table = new Vector<Vector<Integer>>();

    public static void main(String[] args) throws IOException {
                //지지대에서 시작해서 펭귄에게 닿을 수 있는 모든 경로를 각각 구하되,
        //각 지지대 별로 최솟값을 가지고 있자.
        // 그 최소 경오 2개의 합 말곤 전부 다 부술 수 있음.

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());

        for (int i = 0; i <= n; i++) {
            table.add(new Vector<Integer>());
        }
        for (int i = 0; i < n-1; i++) {
            st = new StringTokenizer(br.readLine());
            int from =  Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            table.get(from).add(to);
            table.get(to).add(from);
        }
//        List<Integer> min_list = new ArrayList<>();
//
//        for (int i = 1; i <= s; i++) {
//            min_list.add(get_min(i));
//        }
//        Collections.sort(min_list);
//        int sum = min_list.get(0);
//        sum += min_list.get(1);
//        System.out.println(n - sum - 1);

        dfs(p,-1,0);
        answer.sort((o1, o2) -> o1-o2);
        System.out.println(n-1-answer.get(0)-answer.get(1));
    }

//    public static int get_min(int start) {
//        int visited[] = new int[n+1];
//        Queue<Integer> q = new LinkedList<>();
//        int min_val = 300000;
//        q.add(start);
//        visited[start] = 1;
//
//        while (!q.isEmpty()) {
//            int cur = q.peek();
//            q.remove();
//            for (int i = 0; i < table.get(cur).size(); i++) {
//                int cur_seeing = table.get(cur).get(i);
//                if (visited[cur_seeing] != 0) continue;
//                if (cur_seeing == p) {
//                    if (visited[p] == 0) {
//                        min_val = visited[cur];
//                        visited[p] = visited[cur] + 1;
//                    }
//                    if (visited[cur] + 1 < visited[p]) {
//                        visited[p] = visited[cur] + 1;
//                    }
//                }
//                q.add(cur_seeing);
//                visited[cur_seeing] = visited[cur] + 1;
//            }
//        }
//        return min_val;
//    }

    static ArrayList<Integer> answer=new ArrayList<>();
    static void dfs(int cur,int parent,int cnt)
    {
        if(1<=cur && cur<=s)
        {
            answer.add(cnt);
            return;
        }

        for (int i = 0; i <table.get(cur).size(); i++) {
            int next=table.get(cur).get(i);
            if(next!=parent)
            {
                dfs(next,cur,cnt+1);
            }
        }
    }

}
