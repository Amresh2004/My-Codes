import java.io.*;
import java.util.*;
class vehicle
{
	String cname;
	double price;
	public void accept()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the company name");
		cname = sc.next();
		System.out.println("Enter the vehicle price");
		price = sc.nextDouble();
	}
	public void display()
	{
		System.out.println("Company name is " +cname+ "\n vehicle rice is " +price);
	}
}
class LightMotorVehicle extends vehicle
{
	double milage;
	public void accept()
	{
		super.accept();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the vehicle milage");
		milage = sc.nextDouble();
	}
	public void display()
	{
		super.display();
		System.out.println("Vehicle milage is " +milage);
	}
}
class HeavyMotorVehicle extends vehicle
{
	double capacity;
	public void accept()
	{
		super.accept();
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the vehicle capacity");
		capacity = sc.nextDouble();
	}
	public void display()
	{
		super.display();
		System.out.println("Vehicle capacity is " +capacity);
	}
}
class vdemo
{
	public static void main(String args[])
	{
		int i,ch,n;
		Scanner sc =new Scanner(System.in);
		System.out.println(" Enter the type of vehicle you want:: \n 1.LightMotorVehicle \n 2. HeavyMotorVehicle");
		ch = sc.nextInt();
		switch(ch)
		{
			case 1: System.out.println("How many vehicle you want");
				n = sc.nextInt();
				LightMotorVehicle l[] =new LightMotorVehicle[n];
				for(i=0;i<n;i++)
				{
					l[i]=new LightMotorVehicle();
					l[i].accept();
				}
				System.out.println("******Light Motor Vehicle Informatiom ***********");
				for(i=0;i<n;i++)
					l[i].display();
				break;
			case 2: System.out.println("How many vehicle you want");
				n = sc.nextInt();
				HeavyMotorVehicle h[] =new HeavyMotorVehicle[n];
				for(i=0;i<n;i++)
				{
					h[i]=new HeavyMotorVehicle();
					h[i].accept();
				}
				System.out.println("******Heavy Motor Vehicle Informatiom ***********");
				for(i=0;i<n;i++)
					h[i].display();
				break;
			default : System.out.println("Enter proper choice");
		}
	}
}
