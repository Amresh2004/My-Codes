import java.io.*;
import java.util.*;
interface square
{
	int squarecal();
}
class idemo2 implements square
{
	public int squarecal()
	{
		Scanner sc =new Scanner(System.in);
		int n;
		System.out.println("Enter the number");
		n = sc.nextInt();
		return n*n;
	}
	public static void main(String args[])
	{
		idemo2 i=new idemo2();
		System.out.println("Square of a number is::" +i.squarecal());
	}
}

