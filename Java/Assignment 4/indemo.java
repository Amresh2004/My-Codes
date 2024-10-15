import java.io.*;
import java.util.*;
class vehicle
{
	void display()
	{
		System.out.println("I am in super class vehicle");
	}
}
class twowheeler extends vehicle
{
	void display1()
	{
		System.out.println("I am in extended twowheeler class");
	}
}
class indemo
{
	public static void main(String args[])
	{
		twowheeler t = new twowheeler();
		t.display();
		t.display1();
	}
}
