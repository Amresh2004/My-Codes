import java.util.Scanner;

public class areaofSquare {
    public static void main(String a[])
	{
		float area,side;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the side of square");
		side=sc.nextFloat();
		area=side*side;
		System.out.println("the area of square is "+ area);
	}
}
