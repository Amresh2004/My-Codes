import java.util.Scanner;

public class periofReactangle {
    	public static void main(String a[])
	{
		int Perimeter,Length,Width;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the length of reactabgle");
		Length=sc.nextInt();
		System.out.println("Enter the Width of reactngle");
		Width=sc.nextInt();
		Perimeter=2*(Length+Width);
		System.out.println("Perimeter of Reactangle "+ Perimeter);
	}
}
