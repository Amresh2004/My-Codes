import java.io.*;
import java.util.*;
abstract class order
{
	int id;
	String des;
}
class porder extends order
{
	String cname;
	porder(int id, String des, String cname)
	{
		super.id=id;
		super.des=des;
		this.cname=cname;
	}
	void display()
	{
		System.out.println("ID is::"+super.id+"\n Description is::"+super.des+"\n Customer name is::"+cname);
	}
}
class sorder extends order
{
	String vname;
	sorder(int id, String des, String vname)
	{
		super.id=id;
		super.des=des;
		this.vname=vname;
	}
	void display()
	{
		System.out.println("ID is::"+super.id+"\n Description is::"+super.des+"\n Vendor name is::"+vname);
	}
}
public class p1demo
{
	public static void main(String args[])
	{
		int i,id;
		String des,cname,vname;
		sorder s[]=new sorder[3];
		porder p[]=new porder[3];
		Scanner sc =new Scanner(System.in);
		System.out.println("*****Enter purchase order details******");
		for(i=0;i<3;i++)
		{
			System.out.println("Enter id");
			id=sc.nextInt();
			System.out.println("Enter description");
			des=sc.next();
			System.out.println("Enter cusomer name");
			cname=sc.next();
			p[i]=new porder(id,des,cname);
		}
		System.out.println("*****Enter Sales order details******");
		for(i=0;i<3;i++)
		{
			System.out.println("Enter id");
			id=sc.nextInt();
			System.out.println("Enter description");
			des=sc.next();
			System.out.println("Enter vendor name");
			vname=sc.next();
			s[i]=new sorder(id,des,vname);
		}
		System.out.println("*****Purchase order details******");
		for(i=0;i<3;i++)
			p[i].display();
		System.out.println("*****Sales order details******");
		for(i=0;i<3;i++)
			s[i].display();
	}
}
