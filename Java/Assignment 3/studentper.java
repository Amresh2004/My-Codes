import student1.*;
import java.util.*;
public class studentper
{
	public static double percentage(int total)
	{
		return (total/5);
	}
	public static void main(String a[])
	{
		int rno,n,total,i,j;
		String Class,name;
		double per;
		Scanner sc=new Scanner(System.in);
		int m[]=new int[5];

		System.out.println("How many stuent you want");
		n=sc.nextInt();
		studentinformation s[]=new studentinformation[n];
		for(i=0;i<n;i++)
		{
			total=0;
			System.out.println("Enter Roll Number");
			rno=sc.nextInt();
			System.out.println("Enter Student Name");
			name=sc.next();
			System.out.println("Enter The Class");
			Class=sc.next();
			System.out.println("Enter marks of five subject");
			for(j=0;j<5;j++)
			{
				m[i]=sc.nextInt();
				total=total+m[i];
			}
			per=percentage(total);
			s[i]=new studentinformation(rno,name,Class,per);
		}
		System.out.println("***STUDENT INFORAMTION***");
		System.out.println("Roll no--Name--Class--Percentage");
		for(i=0;i<n;i++)
		{
			s[i].display();
		}
	}
}


