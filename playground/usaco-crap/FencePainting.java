import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

// 2015-december-bronze-p1 Fence Painting
public class FencePainting {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("badmilk.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("badmilks.out")));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		
	
		int[] intervals = new int[]{a, b, c, d};
		ArrayList<Integer> aList = new ArrayList<>();
		ArrayList<Integer> bList = new ArrayList<>();
		
		for (int i = a; i <= b; i++) {
			aList.add(i);
		}
		for (int i = c; i <= d; i++) {
			bList.add(i);
		}
		
		
		if (Collections.disjoint(aList, bList)) {
		// if overlap
			pw.println(Math.abs(Math.abs(d - a) - Math.abs(c - b)));
			pw.close();
		}
		// overlap
		else {	
			Arrays.sort(intervals);
			int max = intervals[intervals.length - 1];
			int min = intervals[0];
			pw.println(max - min);
			pw.close();
		}
		
		
	}
	
}
