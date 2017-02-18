import java.util.Scanner;

public class RepeatRepeatParrot {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.println("What should I say?");
		String phrase = input.nextLine() + "\n";
		System.out.println("How many times should I say it?");
		int amt = input.nextInt();
		
		if (amt < 9 && amt > 0) {
		    String result = (phrase.format("%0" + amt + "d", 0)).replace("0", phrase);
		    System.out.println(result);
		}
	
	
		
	}

}