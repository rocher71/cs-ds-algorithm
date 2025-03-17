import java.util.*;

class Solution {
	public int solution(int[] players, int m, int k) {
		int answer = 0;
		int maxServer = m - 1; // 서버가 감당할 수 있는 인원 수
		ArrayDeque<Integer> serverAppend = new ArrayDeque<>();

		for (int time = 0; time < players.length; time++) {
			while (!serverAppend.isEmpty() && serverAppend.peekFirst() <= time) // 증설된 서버 제거
			{
				serverAppend.removeFirst();
			}

			if ((m - 1) + m * serverAppend.size() < players[time]) {
				int moreServer = (int) Math
						.ceil((double) (players[time] - ((m - 1) + m * serverAppend.size())) / (double) m);

				answer += moreServer;

				for (int i = 0; i < moreServer; i++) {
					serverAppend.addLast(time + k);
				}
			}
		}

		return answer;
	}
}