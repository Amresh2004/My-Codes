import java.util.Scanner;

public class SetA2 
{
     public static void  main(String a[])
	{
		float l,b,area;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the length of reactangle");
		l=sc.nextFloat();
		System.out.println("Enter the breadth of reactangle");
		b=sc.nextFloat();
		area=l*b;
		System.out.println("the area of reactngle "+ area);
	}
}