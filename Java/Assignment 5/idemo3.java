import java.io.*;
import java.util.*;
interface operation
{
	final static double pi= 3.14;
	void volume();
}
class cylinder implements operation
{
	double r,h;
	public void accpet()
	{
		Scanner sc =new Scanner(System.in);
		System.out.println("Enter the radius");
		r = sc.nextFloat();
		System.out.println("Enter the height");
		h = sc.nextFloat();
	}
	public void volume()
	{
		System.out.println("Volume of a cylinder is:: " + (pi*r*r*h));
	}
}
class idemo3
{
	public static void main(String args[])
	{
		cylinder c=new cylinder();
		c.accpet();
		c.volume();
	}
}
