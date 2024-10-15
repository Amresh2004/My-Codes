import java.util.*;
interface markerint
{
}
public class product implements markerint
{
	int pid;
	String pname;
	double cost;
	static int cnt =0;
	product()
	{
		pid =101;
		pname="Pen";
		cost=20;
		cnt++;
	}
	product(int pid, String pname,double cost)
	{
		this.pid =pid;
		this.pname=pname;
		this.cost=cost;
		cnt++;
	}
	void display()
	{
		System.out.println("Product id is::" +pid+ "\n Product name is::" +pname + "\n Product Cost is::" +cost + "\n Object Count is::" +cnt);
	}
	public static void main(String args[]) throws Exception
	{
		int pid,n,i;
		String pname;
		double cost;
		product p = new product();
		System.out.println("********* Default Counstructor Information*********");
		p.display();
		Scanner sc = new Scanner(System.in);
		System.out.println("How many product you want");
		n = sc.nextInt();
		product p1[] = new product[n];
		for(i=0;i<n;i++)
		{ 
			System.out.println("Enter Product id");
			pid = sc.nextInt();
			System.out.println("Enter Product name");
			pname = sc.next();
			System.out.println("Enter Product Cost");
			cost = sc.nextDouble();
			p1[i] = new product(pid,pname,cost);
		}
		System.out.println("********* Parameterised Counstructor Information*********");
		for(i=0;i<n;i++)
			p1[i].display();
	}
}
