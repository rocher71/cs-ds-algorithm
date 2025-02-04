package acmicpc;

import java.io.*;
import java.util.*;

public class Solution_1000_B5_AB {
	public static void main(String[] args) throws IOException {
//		System.setIn(new FileInputStream("res/input_d1_2072.txt"));
		
		
//		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringTokenizer st = null;
//		StringBuilder sb = new StringBuilder();
//
//		int testCase = Integer.parseInt(br.readLine());
//		st = new StringTokenizer(br.readLine());
//		while (st.hasMoreTokens()) {
//			System.out.println(st.nextToken());
//		}

//		br.close();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		System.out.println(n +k);
	}
}
