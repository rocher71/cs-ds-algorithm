package acmicpc;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_2839_S4_설탕배달 {

	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		
		Queue<Point> q = new LinkedList<>();
		boolean[] visit = new boolean[5001];
		for(int i = 1; i<=n; i++) visit[i] = false;
		
		int ans = 0;
		q.add(new Point(n, 0));
		visit[n] = true;
		
		while(!q.isEmpty()) {
			int curr = q.peek().x;
			int currCnt = q.peek().y;
			q.remove();
			
			if(curr == 0) {
				ans = currCnt;
				break;
			}
			
			if(curr>=5 && !visit[curr-5]) {
				q.add(new Point(curr - 5, currCnt + 1));
				visit[curr-5] = true;
			}
			if(curr>=3 && !visit[curr-3]) {
				q.add(new Point(curr - 3, currCnt + 1));
				visit[curr-3] = true;
			}
		}
		if(ans == 0) System.out.println(-1);
		else System.out.println(ans);
	}

}
