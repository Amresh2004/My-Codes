import java.io.*;
import java.util.*;
class cricket
{
	String name;
	int inn,out,runs,avg;
	cricket()
	{
		name = "Dhoni";
		inn = 80;
		out = 10;
		runs = 5000;
	}
	cricket(String name,int inn,int out,int runs)
	{
		this.name= name;
		this.inn= inn;
		this.out=out;
		this.runs=runs;
	}
	static void avgs(cricket c[])
	{
		for(int i=0;i<c.length;i++)
			c[i].avg = c[i].runs / c[i].inn ;
	}
	static void sort(cricket c[])
	{
		int i,j;
		cricket c1= new cricket();
		for(i=0;i<c.length;i++)
		{
			for(j=i+1;j<c.length;j++)
			{
				if(c[i].avg > c[j].avg)
				{
					c1 = c[i];
					c[i]=c[j];
					c[j]=c1;
				}
			}
		}
	}
	void display()
	{
		System.out.println("Player name is:: "+name+ "\n Player innings played are" +inn+ " \n Number of times out " +out+"\n Total runs are " +runs+"\n Batting average is " +this.avg);
	}
	public static void main(String args[])
	{
		Scanner sc =new Scanner(System.in);
		System.out.println("********** Default Information*********");
		cricket c1 =new cricket();
		c1.display();
		int n,i;
		String name;
		int inn,out,runs,avg;
		System.out.println("How many player information you want");
		n = sc.nextInt();
		cricket c[] = new cricket[n];
		for(i =0;i<n;i++)
		{
			System.out.println("Enter the player name");
			name= sc.next();
			System.out.println("Enter the player innings played");
			inn=sc.nextInt();
			System.out.println("Enter the player number of times out");
			out=sc.nextInt();
			System.out.println("Enter the players total runs");
			runs=sc.nextInt();
			c[i]=new cricket(name,inn,out,runs);
		}
		System.out.println("**********Player Information*********");
		avgs(c);
		for(i =0;i<n;i++)
			c[i].display();
		sort(c);
		System.out.println("**********Player Information after sorting according to batting avg*********");
		for(i =0;i<n;i++)
			c[i].display();
	}
}

