
import java.util.*;
import java.io.*;

public class Main {

	static int row, col, minsikY, minsikX, ans;
	/*
	 * row : 행, col : 열
	 * minsikY : 민식이의 초기 y좌표, minsikX : 민식이의 초기 x좌표
	 * ans : 정답 (이동 횟수)
	 */
	static int arr[][]; // 문제에서 주어지는 미로
	static int dy[] = {0, 0, -1, 1}, dx[] = {-1, 1, 0, 0};
	static boolean visit[][][];
	/*
	 * 방문 체크 함수, [y][x][key]
	 *  -> (y, x) 좌표에 key 를 가지고 방문한 적이 있는지
	 *  이때 key는 비트마스킹 한 값
	 *  32 = 100000 -> 6번(f)키를 가지고 방문한 적이 있음
	 *  36 = 100100 -> 6번(f), 3번(c)키를 가지고 방문한 적이 있음
	 */
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		row = Integer.parseInt(st.nextToken());
		col = Integer.parseInt(st.nextToken());
		
		arr = new int[row + 1][col + 1];
		visit = new boolean[row + 1][col + 1][200];
		
		for(int i = 0; i< row; i++) {
			st = new StringTokenizer(br.readLine());
			String str = st.nextToken();
			
			for(int j = 0; j< col; j++) {
				char c = str.charAt(j);
				if(c == '.') continue; // 이동 가능한 칸
				if(c == '#') { // 벽
					arr[i][j] = -1;
					continue;
				}
				if(c == '0') { // 출발점
					minsikY = i;
					minsikX = j;
					continue;
				}
				if(c == '1') { // 목적지
					arr[i][j] = 1;
					continue;
				}
				arr[i][j] = c - 0; // 그 외 a~b, A~B
			}
		}
		
		bfs();
		
		System.out.println(ans == 0 ? -1 : ans);

	}
	
	static void bfs() {
		Queue<int[]> q = new ArrayDeque<>();
		visit[minsikY][minsikX][0] = true;
		q.offer(new int[] {minsikY, minsikX, 0, 0}); // y, x, 거리, 키
		
		while(!q.isEmpty()) {
			int currY = q.peek()[0];
			int currX = q.peek()[1];
			int currDist = q.peek()[2];
			int keys = q.poll()[3];
			
			if(arr[currY][currX] == 1) {
				ans = currDist;
				return;
			}
			
			for(int i = 0; i< 4; i++) {
				int ny = currY + dy[i];
				int nx = currX + dx[i];
				int newKey = keys;
				
				if(ny < 0 || nx < 0 || ny >= row || nx >= col) continue;
				//System.out.println(keys + " " + visit[ny][nx] + " "+(visit[ny][nx] & keys));
				
				 // 벽, 같은 키를 가지고 방문했을 경우, 키 없을때 방문한 경우
				if(arr[ny][nx] == -1 
						|| (keys != 0 && visit[ny][nx][keys]) 
						|| (keys == 0 && visit[ny][nx][0] == true)
						) continue;
				if(arr[ny][nx] >= 'A' && arr[ny][nx] <= 'F' && ((keys & (1 << arr[ny][nx] - 'a')) == 0)) continue; // 키가 없을때
				
				// 키 획득
				if(arr[ny][nx] >= 'a' && arr[ny][nx] <= 'f') newKey =  keys | (1 << (arr[ny][nx] - 'a'));  
					//hasKey[arr[ny][nx] - 'a'] = true;
				
				q.offer(new int[] {ny, nx, currDist + 1, newKey});
				if(newKey != 0) visit[ny][nx][newKey] = true;
				else visit[ny][nx][0] = true;
				
			}
		}
		
	}

}












