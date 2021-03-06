import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

// worked by myself 

public class Challenge {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		BufferedReader br = null;
		
		String[] elements = new String[4];
		System.out.println("Where is your file?");
		String location = input.nextLine();
		location += "CSLab01ABC.txt";
		
		for (int i = 0; i < 4; i++) {
			System.out.println("Give a Letter");
			elements[i] = input.nextLine().toLowerCase();
		}	
		
		try {
			br = new BufferedReader(new FileReader(location));
			
			// "Files.readAllLines(Paths.get(x)).get(y)" ==> reads specific line from file
			
			for (int y=1; y<6; y++) {
				for (int x=0; x<4; x++) {
					if (elements[x].equals("a")) {
						// "y - 1" because notepad starts from line 0
						System.out.print(Files.readAllLines(Paths.get(location)).get(y-1));
					}
					else if (elements[x].equals("b")) {
						System.out.print(Files.readAllLines(Paths.get(location)).get(y+4));
					}
					else if (elements[x].equals("c")) {
						System.out.print(Files.readAllLines(Paths.get(location)).get(y+9));
					}
					else {
						System.out.print("          ");
					}
					
				}
				System.out.print("\n");
			}
			
	
		
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
					ex.printStackTrace();
			}
		}

	}

}