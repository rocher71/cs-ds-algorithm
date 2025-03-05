import java.io.*;
import java.util.*;

public class Main {
	static int row, col;
	static int[][] cleanMap;
	static int cleanedRoom = 0;

	public static void clean(int x, int y) {
		if (cleanMap[x][y] == 0) {
			cleanMap[x][y] = 2;
			cleanedRoom++;
		}
	}

	public static boolean find(int x, int y, int drct) {
		if (drct == 0 && y > 0 && cleanMap[x][y - 1] == 0)
			return true;
		if (drct == 1 && x > 0 && cleanMap[x - 1][y] == 0)
			return true;
		if (drct == 2 && y < col - 1 && cleanMap[x][y + 1] == 0)
			return true;
		if (drct == 3 && x < row - 1 && cleanMap[x + 1][y] == 0)
			return true;
		return false;
	}

	public static int rotate(int drct) {
		return (drct + 3) % 4;
	}

	public static int[] move(int x, int y, int drct) {
		if (drct == 0 && x > 0)
			x--;
		else if (drct == 1 && y < col - 1)
			y++;
		else if (drct == 2 && x < row - 1)
			x++;
		else if (drct == 3 && y > 0)
			y--;
		return new int[] { x, y };
	}

	public static int[] moveBack(int x, int y, int drct) {
		int newX = x, newY = y;
		boolean moveBackFlag = false;

		if (drct == 0 && x < row - 1) {
			newX++;
			moveBackFlag = true;
		} else if (drct == 1 && y > 0) {
			newY--;
			moveBackFlag = true;
		} else if (drct == 2 && x > 0) {
			newX--;
			moveBackFlag = true;
		} else if (drct == 3 && y < col - 1) {
			newY++;
			moveBackFlag = true;
		}

		if (cleanMap[newX][newY] == 1)
			moveBackFlag = false;

		return new int[] { newX, newY, moveBackFlag ? 1 : 0 };
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		row = Integer.parseInt(st.nextToken());
		col = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int direction = Integer.parseInt(st.nextToken());

		cleanMap = new int[row][col];
		for (int i = 0; i < row; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < col; j++) {
				cleanMap[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int rotateCount = 0;
		while (true) {
			if (rotateCount >= 4) {
				int[] back = moveBack(x, y, direction);
				x = back[0];
				y = back[1];
				if (back[2] == 0)
					break;
				rotateCount = 0;
			}

			clean(x, y);

			if (find(x, y, direction)) {
				rotateCount = 0;
				direction = rotate(direction);
				int[] newPos = move(x, y, direction);
				x = newPos[0];
				y = newPos[1];
			} else {
				direction = rotate(direction);
				rotateCount++;
			}
		}

		System.out.println(cleanedRoom);
	}
}
