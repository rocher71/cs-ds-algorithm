

import java.io.*;
import java.util.*;

public class Main {
    static int n, m, departure, arrival;
    static List<int[]>[] graph;
    static int[] dist;

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());

        dist = new int[n+1];
        graph = new ArrayList[n + 1];
        for(int i = 1; i<= n ;i++) graph[i] = new ArrayList<>();

        for(int i = 0; i < m; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            graph[from].add(new int[]{to, cost});
        }

        st = new StringTokenizer(br.readLine());
        departure = Integer.parseInt(st.nextToken());
        arrival = Integer.parseInt(st.nextToken());

        for(int i = 1; i<= n; i++) dist[i] = Integer.MAX_VALUE;
        dijk();

        System.out.println(dist[arrival]);
    }

    static void dijk(){
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.add(new int[]{0, departure});
        dist[departure] = 0;

        while(!pq.isEmpty()){
            int currCost = pq.peek()[0];
            int curr = pq.poll()[1];

            if(curr == arrival) return;

            for(int i = 0; i< graph[curr].size(); i++){
                int next = graph[curr].get(i)[0];
                int nextCost = graph[curr].get(i)[1];
                int newCost = currCost + nextCost;

                if(dist[next] <= newCost) continue;

                pq.add(new int[]{newCost, next});
                dist[next] = newCost;
            }
        }
    }
}
