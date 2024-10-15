import java.io.*;
import java.util.*;
class edemo1
{
	public static void main(String args[])
	{
		int a[] = {1,2,3};
		try
		{
			System.out.println(a[3]);
		}
		catch(Exception e)
		{
			System.out.println("Exception caugth" +e);
		}
		System.out.println("my execption program");
	}
}
