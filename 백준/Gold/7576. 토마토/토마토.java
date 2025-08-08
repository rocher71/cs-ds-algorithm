
import java.util.*;
import java.io.*;

public class Main {
    static int row, col, ripeCnt, noCnt;
    static int[][] arr, days;
    static int[] dy = {0, 0, -1, 1}, dx = {-1, 1, 0, 0};
    static Deque<int[]> q = new ArrayDeque<>();

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        col = Integer.parseInt(st.nextToken());
        row = Integer.parseInt(st.nextToken());

        arr = new int[row][col];
        days = new int[row][col];

        for(int i = 0 ; i< row; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j< col; j++){
                arr[i][j] = Integer.parseInt(st.nextToken());
                if(arr[i][j] == 1){
                    ripeCnt++;
                    q.add(new int[]{i, j});
                    days[i][j] = 0;
                }
                else if(arr[i][j] == -1){
                    noCnt++;
                    days[i][j] = -1;
                }
            }
        }

        if(ripeCnt == row * col - noCnt){
            System.out.println(0);
            return;
        }

        bfs();

        int maxDays = Integer.MIN_VALUE;
        for(int i = 0; i< row; i++){
            for(int j = 0 ;j < col; j++){
                if(arr[i][j] == 1 || days[i][j] != 0){
                    maxDays = Integer.max(maxDays, days[i][j]);
                    continue;
                }

                if(arr[i][j] != 1 && days[i][j] == 0){
                    System.out.println(-1);
                    return;
                }
            }
        }

        System.out.println(maxDays);


    }

    static void bfs(){
        while(!q.isEmpty()){
            int currY = q.peek()[0];
            int currX = q.poll()[1];
            int currDays = days[currY][currX];

            for(int i = 0 ; i < 4; i++){
                int nextY = currY + dy[i];
                int nextX = currX + dx[i];

                if(nextY < 0 || nextX < 0 || nextY >= row || nextX >= col) continue;
                if(arr[nextY][nextX] != 0) continue; // 토마토가 이미 있던 부분(초기에 다 넣음)이나 -1인 부분이면 pass
                if(arr[nextY][nextX] == 0 && days[nextY][nextX] != 0 && days[nextY][nextX] <= currDays + 1) continue;

                days[nextY][nextX] = currDays + 1;
                q.add(new int[]{nextY, nextX});
            }
        }
    }
}
