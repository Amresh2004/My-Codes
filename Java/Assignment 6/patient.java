import java.io.*;
import java.util.*;
class CovidException extends Exception
{
	CovidException()
	{
		System.out.print("Patient is Covid Positive, need to be hospitalized::");
	}
}
class patient
{
	String pname;
	int age,olevel,hrct;
	patient(String pname,int age,int olevel,int hrct)
	{
		this.pname=pname;
		this.age=age;
		this.olevel=olevel;
		this.hrct=hrct;
	}
	public static void main(String args[])
	{
		String pname;
		int age,olevel,hrct;
		Scanner sc = new Scanner(System.in);
		try
		{
			System.out.println("Enter Patient name");
			pname = sc.next();
			System.out.println("Enter Patient age");
			age = sc.nextInt();
			System.out.println("Enter Patient Oxygen level");
			olevel = sc.nextInt();
			System.out.println("Enter Patient HRCT scan report");
			hrct = sc.nextInt();
			patient p =new patient(pname,age,olevel,hrct);
			if(olevel < 95 && hrct > 10)
				throw new CovidException();
			else
				System.out.println("Patient name is::"+pname+"\n Patient age is::"+age+"\n Patient olevel is::"+ 
						olevel+"\n Patient HRCT is::"+ hrct);
		}
		catch(CovidException e)
		{
			System.out.println(e);
		}
	}
}

