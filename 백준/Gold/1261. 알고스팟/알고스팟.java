

import java.io.*;
import java.util.*;

public class Main {
    static int row, col;
    static int[][] arr, cnt;
    static boolean[][] visit;
    static int[] dy = {0, 0, -1, 1}, dx = {-1, 1, 0, 0};

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        col = Integer.parseInt(st.nextToken());
        row = Integer.parseInt(st.nextToken());

        arr = new int[row][col];
        cnt = new int[row][col];
        visit = new boolean[row][col];

        for(int i = 0 ;i < row; i++){
            String str = br.readLine();
            for(int j = 0 ;j < col; j++){
                arr[i][j] = str.charAt(j) - '0';
            }
        }

        dijk();

        System.out.println(cnt[row - 1][col - 1]);
    }

    static void dijk(){
        Deque<int[]> q = new ArrayDeque<>();
        if(arr[0][0] == 1) cnt[0][0] = 1;
        else cnt[0][0] = 0;
        q.add(new int[]{0, 0});
        visit[0][0] = true;

        while(!q.isEmpty()){
            int currY = q.peek()[0];
            int currX = q.poll()[1];
            int currCnt = cnt[currY][currX];

            for(int i = 0 ;i< 4; i++){
                int nextY = currY + dy[i];
                int nextX = currX + dx[i];
                int nextCnt = currCnt;

                if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
                if(arr[nextY][nextX] == 1) nextCnt++;
                if(visit[nextY][nextX] && cnt[nextY][nextX] <= nextCnt) continue;

                q.add(new int[]{nextY, nextX});
                cnt[nextY][nextX] = nextCnt;
                visit[nextY][nextX] = true;
            }
        }
    }
}
