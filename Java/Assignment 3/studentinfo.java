import SY.*;
import TY.*;
import java.util.*;
class student
{
	int rno,syt,tyt,gt;
	String name,grade;
	float per;
	public void getdata()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the roll number");
		rno=sc.nextInt();
		System.out.println("Enter the name of student");
		name=sc.next();
	}
}

class studentinfo
{
	public static void main(String a[])
	{
		Scanner sc=new Scanner(System.in);
		int i,n;
		System.out.println("How many student you want");
		n=sc.nextInt();
		student si[]=new student[n];
		syclass s[]=new syclass[n];
		tyclass t[]=new tyclass[n];
		System.out.println("Enter" + n + "records");
		for(i=0;i<n;i++)
		{
			si[i]=new student();
			s[i]=new syclass();
			t[i]=new tyclass();

			si[i].getdata();
			s[i].getdata();
			t[i].getdata();

			si[i].syt=s[i].ct + s[i].mt + s[i].et;
			si[i].tyt=t[i].th + t[i].prac;

			si[i].gt=si[i].syt + si[i].tyt;

			si[i].per=si[i].gt/9;

			if(si[i].per >=70)
			{
				si[i].grade="A";
			}
			else if(si[i].per < 70 && si[i].per >=60)
			{
				si[i].grade="B";
			}
			else if(si[i].per < 60 && si[i].per >=50)
			{
				si[i].grade="C";
			}
			else if(si[i].per < 50 && si[i].per >=40)
			{
				si[i].grade="PASS";
			}
			else
			{
				si[i].grade="FAIL";
			}
		}
		System.out.println("***STUDENT INFORMATION***");
		System.out.println("Roll number \t Name \t SY total \t TY total \t Grand Total \t Percentage \t Grade");
		for(i=0;i<n;i++)
		{
			System.out.println(si[i].rno + "\t" + si[i].name + "\t" + si[i].syt + "\t" + si[i].tyt + "\t" + si[i].gt + "\t" +si[i].per + "\t" + si[i].grade);
		}
	}
}


