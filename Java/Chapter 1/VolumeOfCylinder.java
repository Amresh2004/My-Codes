import java.util.Scanner;

public class VolumeOfCylinder {
    public static void main(String a[])
	{
		double radius,height,volume;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the radius of cyclinder");
		radius=sc.nextDouble();
		System.out.println("Enter the height of cyclinder");
		height=sc.nextDouble();
		volume=3.14*radius*radius*height;
		System.out.println("Voulme Of Cyclinder "+ volume);
	}
}
