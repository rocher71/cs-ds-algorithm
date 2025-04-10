package selfStudy;

import java.io.*;
import java.util.*;

public class Solution_d_4014_활주로건설_서울_14반_김예진 {
	static int tc, ans, n, x;
	static int arr[][];
	static ArrayList<Integer> numbers = new ArrayList<>();
	static ArrayList<Integer> cnts = new ArrayList<>();

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		tc = Integer.parseInt(st.nextToken());
		for(int t = 1; t<= tc; t++) {
			
			ans = 0;
			st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			x = Integer.parseInt(st.nextToken());
			arr = new int[n][n];
			
			for(int i = 0 ;i < n;i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j< n; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			// 배열 회전하기 때문에 2회 실행
			for(int r = 0; r < 2; r++) {
				int prev, cnt;
				
				// 각 행별로
				for(int i = 0; i< n; i++) {
					numbers.clear();
					cnts.clear();
					
					// 이어지는 숫자 및 이어지는 개수 저장
					prev = arr[i][0];
					cnt = 1;
					for(int j = 1; j< n; j++) {
						if(arr[i][j] == prev) { // 같은 숫자가 이어지는 경우
							cnt++;
							continue;
						}
						// 같은 숫자가 이어지지 않음
						numbers.add(prev);
						cnts.add(cnt);
						prev = arr[i][j];
						cnt = 1;
					}
					numbers.add(prev);
					cnts.add(cnt);
					
					
					// 한 줄의 숫자가 모두 같은 경우 가능
					if(numbers.size() == 1) {
						ans++;
						//System.out.println(r + " : " + i);
						continue;
					}
					
					// 건설할 수 있는 경우 답+1
					boolean isAvail = checkRow();
					if(isAvail) {
						ans++;
						//System.out.println(r + " : " + i);
					}
				}
				
				// 시계방향으로 90도 회전
				rotate();
			}
			
			System.out.println("#" + t + " " + ans);
		}
	}
	
	static boolean checkRow() {
		int small, big;
		// 행에 활주로 설치가 가능한지 확인
		for(int j = 0; j < numbers.size() - 1; j++) {
			//if(isBuilt[j] && numbers.get(j) != numbers.get(j + 1)) return false;
			// 숫자 간 차이가 1이 아니라면 활주로 건설 불가
			if(Math.abs(numbers.get(j) - numbers.get(j + 1)) != 1)  return false;
			
			// 큰 수와 작은 수의 idx 저장
			big = numbers.get(j) > numbers.get(j + 1) ? j : j + 1;
			small = big == j ? j + 1 : j;
			
			// 낮은 쪽의 개수가 x 보다 작다면 불가능
			if(cnts.get(small) < x) return false;
			
			//for(int i = idx; i < cnts.get(j); i++) isBuilt[i] = true;
			//idx += cnts.get(j);
			
			// 짧은 쪽의 길이가 x와 같으면 넘어감
			//if(cnts.get(small) == x) continue; -> 얘 땜에 틀렸었음
			// 짧은 쪽의 길이가 x 보다 길면 길이에서 x만큼 빼줌. 그리고 다음 뭉텅이와 비교
			cnts.set(small, cnts.get(small) - x);
		}
		return true;
	}
	
	// 2차원 배열 90도 회전
	static void rotate() {
		int newArr[][] = new int[n][n];
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j< n; j++) {
				newArr[i][j] = arr[n - 1 - j][i];
			}
		}
		
		for(int i = 0; i< n; i++) arr[i] = newArr[i];
	}

}
