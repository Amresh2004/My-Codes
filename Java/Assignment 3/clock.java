import java.io.*;
import java.util.*;
class clock
{
	int h,m,s;
	clock()
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the hours");
		h = sc.nextInt();
		System.out.println("Enter the mins");
		m = sc.nextInt();
		System.out.println("Enter the secs");
		s = sc.nextInt();
	}
	void isTimevalid()
	{
		if(h>=0 && h<=24 && m>=0 && m<=60 && s>=0 && m<=60)
			System.out.println("Time is Valid");
		else
			System.out.println("Time is not Valid");
	}
	void setTime()
	{
		if(h < 12)
			System.out.println(" Time is:: "+h+":"+m+":"+s+ "AM");
		else
		{
			h=h-12;
			System.out.println(" Time is:: "+h+":"+m+":"+s+ "PM");
		}
	}
	public static void main(String args[])
	{
		clock c = new clock();
		c.isTimevalid();
		c.setTime();
	}
}

