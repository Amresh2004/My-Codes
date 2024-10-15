import java.io.*;
import java.util.*;
abstract class shape
{
	int n1,n2;
	public abstract void printarea();
}
class circle extends shape
{
	circle(int a)
	{
		super.n1= a;
	}
	public void printarea()
	{
		System.out.println("Area of cirlce is:: "+(3.14*super.n1*super.n1));
	}
}
class rectangle extends shape
{
	rectangle(int l,int b)
	{
		super.n1= l;
		super.n2 = b;
	}
	public void printarea()
	{
		System.out.println("Area of Rectangle is:: "+(super.n1*super.n2));
	}
}
class triangle extends shape
{
	triangle(int h,int b)
	{
		super.n1= h;
		super.n2 = b;
	}
	public void printarea()
	{
		System.out.println("Area of Triangle is:: "+(super.n1*super.n2)/2);
	}
}
class sdemo
{
	public static void main(String args[])
	{
		circle c = new circle(2);
		rectangle r=new rectangle(4,5);
		triangle t=new triangle(3,2);
		c.printarea();
		r.printarea();
		t.printarea();
	}
}
