

import java.util.*;
import java.io.*;

public class Main {
    static int tc, row, col, k;
    static boolean[][] visit, arr;
    static int[] dy = new int[] {0, 0, -1, 1}, dx = new int[]{-1, 1, 0, 0};

    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        tc = Integer.parseInt(st.nextToken());

        while(tc-- != 0){
            st = new StringTokenizer(br.readLine());
            col = Integer.parseInt(st.nextToken());
            row = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            arr = new boolean[row][col];
            visit = new boolean[row][col];

            for(int i = 0; i< k; i++){
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                arr[y][x] = true;
            }

            int cnt = 0;
            for(int i = 0; i< row; i++){
                for(int j = 0; j < col; j++){
                    if(visit[i][j] || !arr[i][j]) continue;
                    bfs(i, j);
                    cnt++;
                }
            }

            System.out.println(cnt);
        }
    }

    static void bfs(int y, int x){
        Deque<int[]> q = new ArrayDeque<>();
        q.add(new int[]{y, x});
        visit[y][x] = true;

        while(!q.isEmpty()){
            int currY = q.peek()[0];
            int currX = q.poll()[1];

            for(int i = 0; i< 4; i++){
                int nextY = currY + dy[i];
                int nextX = currX + dx[i];

                if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
                if(visit[nextY][nextX] || !arr[nextY][nextX]) continue;

                q.add(new int[]{nextY, nextX});
                visit[nextY][nextX] = true;
            }
        }
    }
}