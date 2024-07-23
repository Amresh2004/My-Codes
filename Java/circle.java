import java.util.Scanner;

public class circle {
    public static void main(String a[])
    {
        double radius,area;
		Scanner sc=new Scanner(System.in);
		System.out.println("ENter the radius");
		radius=sc.nextDouble();
		area=3.14*radius*radius;
		System.out.println("Area of Circle is "+ area);
    }
}
