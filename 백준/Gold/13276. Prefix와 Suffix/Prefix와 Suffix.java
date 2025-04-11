
import java.io.*;
import java.util.*;
import java.util.zip.CheckedOutputStream;

public class Main {

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String textStr = br.readLine();
		String patternAStr = br.readLine();
		String patternBStr = br.readLine();
		char[] text = textStr.toCharArray();
		char[] patternA = patternAStr.toCharArray();
		char[] patternB = patternBStr.toCharArray();
		
		int pa[] = new int[patternA.length];
		int pb[] = new int[patternB.length];
		
		for(int i = 1, j = 0; i < patternA.length; i++) {
			while(j > 0 && patternA[i] != patternA[j]) {
				j = pa[j - 1];
			}
			
			if(patternA[i] == patternA[j]) {
				pa[i] = ++j;
			}
		}
		
		for(int i = 1, j = 0; i < patternB.length; i++) {
			while(j > 0 && patternB[i] != patternB[j]) {
				j = pb[j - 1];
			}
			
			if(patternB[i] == patternB[j]) {
				pb[i] = ++j;
			}
		}
//		System.out.println(Arrays.toString(pa));
//		System.out.println(Arrays.toString(pb));
		
		ArrayList<Integer> aList = new ArrayList<>();
		ArrayList<Integer> bList = new ArrayList<>();
		for(int i = 0, j = 0; i< text.length; i++) {
			while(j > 0 && text[i] != patternA[j]) {
				j = pa[j - 1];
			}
			
			if(text[i] != patternA[j]) continue; 
			
			if(j == patternA.length - 1) {
				aList.add(i - j);
				j = pa[j];
				continue;
			}
			
			j++;
		}
		
		for(int i = 0, j = 0; i< text.length; i++) {
			while(j > 0 && text[i] != patternB[j]) {
				j = pb[j - 1];
			}
			
			if(text[i] != patternB[j]) continue; 
			
			if(j == patternB.length - 1) {
				bList.add(i - j);
				j = pb[j];
				continue;
			}
			
			j++;
		}
		
//		System.out.println(aList);
//		System.out.println(bList);
		
		// 패턴 a의 뒷부분과 b의 앞부분을 보며 겹치는 곳이 있는지 찾기 
//		int sameCnt = 0;
//		for(int i = 0; i < patternA.length; i++) {
//			if(i >= patternB.length) break;
//			if(patternA[patternA.length - 1 - i] != patternB[i]) break;
//			sameCnt++;
//		}
		
		
		//int cnt = 0;
		Set<String> s = new HashSet<>();
		for(int i = 0; i < aList.size(); i++) {
			for(int j = 0; j < bList.size(); j++) {
				if(aList.get(i) == -1 || bList.get(j) == -1) continue;
				if(aList.get(i) > bList.get(j) || bList.get(j) + patternB.length > text.length) continue;
				String sub = textStr.substring(aList.get(i), bList.get(j) + patternB.length);
				if(!sub.startsWith(patternAStr) || !sub.endsWith(patternBStr)) continue;
//				System.out.println(sub);
				s.add(sub);
				
				//text[j] = '0';
//				aList.set(i, -1);
//				bList.set(j, -1);
//				break;
			}
			//if(i >= bList.size()) break;
//			if(aList.get(i) + patternA.length  <= bList.get(i)) cnt++;
			
		}
		System.out.println(s.size());
	}

}


/*
abcdeefa
abcdee
cd

a
asdfsafasd
asfsadfsaf

asdasdf
asd
f
 */














