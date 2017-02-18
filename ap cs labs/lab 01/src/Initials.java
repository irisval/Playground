import java.util.Scanner;

public class Initials {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		String c1, c2, c3;
		
		System.out.println("What is the 1st letter you want?");
		c1 = input.nextLine();
		System.out.println("What is the 2nd letter you want?");
		c2 = input.nextLine();
		System.out.println("What is the 3rd letter you want?");
		c3 = input.nextLine();
		

		
		System.out.println(String.format("%1$s%1$s%1$s%1$s%1$s%1$s%1$s  %2$s%2$s%2$s   %2$s%2$s%2$s  %3$s%3$s%3$s   %3$s%3$s%3$s ", c1, c2, c3));
		System.out.println(String.format("%1$s%1$s%1$s %1$s%1$s%1$s   %2$s %2$s %2$s %2$s   %3$s %3$s  %3$s %3$s", c1, c2, c3));
		System.out.println(String.format("  %1$s %1$s      %2$s %2$s %2$s    %3$s %3$s %3$s %3$s", c1, c2, c3));
		System.out.println(String.format("  %1$s %1$s       %2$s %2$s     %3$s %3$s %3$s %3$s", c1, c2, c3));
		System.out.println(String.format("%1$s%1$s%1$s %1$s%1$s%1$s     %2$s %2$s     %3$s %3$s  %3$s %3$s", c1, c2, c3));
		System.out.println(String.format("%1$s%1$s%1$s%1$s%1$s%1$s%1$s     %2$s%2$s%2$s     %3$s%3$s%3$s   %3$s%3$s%3$s", c1, c2, c3));
		
		
	}

}