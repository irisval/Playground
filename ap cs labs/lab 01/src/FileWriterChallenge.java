import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

// worked by myself 

public class FileWriterChallenge {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		BufferedReader br = null;
		String location, newFile;
		
		String[] elements = new String[4];
		System.out.println("Where is your file?");
		location = input.nextLine();
		location += "CSLab01ABC.txt";
		System.out.println("Which file should the output be written to?");
		newFile = input.nextLine();
		
		for (int i = 0; i < 4; i++) {
			System.out.println("Give a Letter");
			elements[i] = input.nextLine();
		}	
		
		input.close();
		
		/////write to file
		try {		
			File file = new File(newFile);
			FileWriter fw;
			
			if (!file.exists()) {
				file.createNewFile();
				fw = new FileWriter(file.getAbsoluteFile());
			}
			else {
				// appends to existing file
				fw = new FileWriter(file.getAbsoluteFile(), true);
			}
			
			BufferedWriter bw = new BufferedWriter(fw);
			/////read to file
			try {
				br = new BufferedReader(new FileReader(location));	
				
				for (int y=1; y<6; y++) {
					for (int x=0; x<4; x++) {
						if (elements[x].equals("a")) {
							bw.write(Files.readAllLines(Paths.get(location)).get(y-1));
						}
						else if (elements[x].equals("b")) {
							bw.write(Files.readAllLines(Paths.get(location)).get(y+4));
						}
						else if (elements[x].equals("c")) {
							bw.write(Files.readAllLines(Paths.get(location)).get(y+9));
						}
						else {
							bw.write("          ");
						}	
					}
					bw.newLine();
					
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
			//
			
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}			
			
}