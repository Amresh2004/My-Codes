import java.io.*;
import java.util.*;
interface cube
{
	int cubecal();
}
class idemo implements cube
{
	public int cubecal()
	{
		Scanner sc =new Scanner(System.in);
		int n;
		System.out.println("Enter the number");
		n = sc.nextInt();
		return n*n*n;
	}
	public static void main(String args[])
	{
		idemo i=new idemo();
		System.out.println("Cube of a number is::" +i.cubecal());
	}
}

