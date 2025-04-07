
import java.util.*;
import java.io.*;

public class Main {

	static int row, col, minsikY, minsikX, ans;
	static int arr[][];
	static int dy[] = {0, 0, -1, 1}, dx[] = {-1, 1, 0, 0};
	static boolean visit[][][];
	
	public static void main(String[] args) throws Exception{
		
//		System.out.println('A' - 0);
//		System.out.println('a' - 0);
//		System.out.println('a' - 'a');
//		System.out.println('A' - 'a');
//		System.out.println('a' - 'A');
//		System.out.println(1 << 'a' - 'a');
//		System.out.println(1 << 'b' - 'a');
//		System.out.println(1 << 'c' - 'a');
//		System.out.println(1 << 'd' - 'a');
//		System.out.println(1 << 'e' - 'a');
//		System.out.println(1 << 'f' - 'a');
		
//		System.out.println(2 & (1 << 'F' - 'a'));
//		System.out.println(1 << 'F' - 'a');
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
				if(c == '.') continue;
				if(c == '#') {
					arr[i][j] = -1;
					continue;
				}
				if(c == '0') {
					minsikY = i;
					minsikX = j;
					continue;
				}
				if(c == '1') {
					arr[i][j] = 1;
					continue;
				}
				arr[i][j] = c - 0;
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
			
//			System.out.println("(" + currY + ", " + currX + ") " + currDist + " " + keys);
//			for(int i = 0; i< row; i++) {
//				for(int j = 0; j< col; j++) {
//					if(i == currY && j == currX) {
//						System.out.print("X ");
//						continue;
//					}
//					System.out.print(arr[i][j] + " ");
//				}
//				System.out.println();
//			}
//			System.out.println();
			
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
				if(arr[ny][nx] == -1 || (keys != 0 && visit[ny][nx][keys]) || (keys == 0 && visit[ny][nx][0] == true)) continue; // 벽
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












