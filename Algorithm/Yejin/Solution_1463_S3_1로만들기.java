package acmicpc;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution_1463_S3_1로만들기 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		
		Queue<Point> q = new LinkedList<>();
		boolean[] visit = new boolean[n + 1];
		q.add(new Point(n, 0));
		visit[n] = true;
		
		int ans = 0;
		
		while(!q.isEmpty()) {
			int curr = q.peek().x;
			int currCnt = q.peek().y;
			q.remove();
			
			if(curr == 1) {
				ans = currCnt;
				break;
			}
			
			if(curr%3 == 0 && !visit[curr/3]) q.add(new Point(curr/3, currCnt+1));
			if(curr%2 == 0 && !visit[curr/2]) q.add(new Point(curr/2, currCnt+1));
			if(!visit[curr-1]) q.add(new Point(curr -1, currCnt + 1));
		}
		
		System.out.println(ans);
	}

}
