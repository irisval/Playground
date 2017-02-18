import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

// 2015-december-bronze-p1 Speeding Ticket

public class SpeedingTicket {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("speedingticket.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("speedingticket.out")));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		int[] speedingLimits = new int[n * 2];
		int[] speed = new int[n * 2];
		
		for (int i = 0; i < n * 2; i++) 
			speedingLimits[i] = Integer.parseInt(st.nextToken());
		for (int i = 0; i < m * 2; i++)
			speed[i] = Integer.parseInt(st.nextToken());
		
		int[] cont1 = new int[100];
		int[] cont2 = new int[100];
		int count = 0;
		int highest = 0;
		
		for (int i = 0; i < speedingLimits.length; i+=2) {
			for (int j = 0; j < speedingLimits[i]; j++) {
				cont1[count] = speedingLimits[i+1];
				count++;
			}
		}
		
		count = 0;
		for (int i = 0; i < speed.length; i+=2) {
			for (int j = 0; j < speed[i]; j++) {
				cont2[count] = speed[i+1]; 
				count++;
			}
		}
		
		for (int i = 0; i < 100; i++) {
			if (cont2[i] - cont1[i] > highest)
				highest = cont2[i] - cont1[i];
		}
		pw.println(highest);
		pw.close();
	
		
		
		
	}
	
}
