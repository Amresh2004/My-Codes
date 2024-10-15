import java.io.*;
import java.util.*;
class continent
{
	String cont;
	Scanner sc =new Scanner(System.in);
	void cont_input()
	{
		System.out.println("Enter the continent name");
		cont = sc.next();
	}
}
class country extends continent
{
	String con;
	Scanner sc =new Scanner(System.in);
	void con_input()
	{
		System.out.println("Enter the contry name");
		con = sc.next();
	}
}
class state extends country
{
	String sta;
	Scanner sc =new Scanner(System.in);
	void sta_input()
	{
		System.out.println("Enter the State name");
		sta = sc.next();
	}
}
class place extends state
{
	String pla;
	Scanner sc =new Scanner(System.in);
	void pla_input()
	{
		System.out.println("Enter the Place name");
		pla = sc.next();
	}
}
class indemo2 extends place
{
	public static void main(String args[])
	{
		indemo2 p = new indemo2();
		p.cont_input();
		p.con_input();
		p.sta_input();
		p.pla_input();
		System.out.println("Continent name is :: " + p.cont);
		System.out.println("Country name is :: " + p.con);
		System.out.println("State name is :: " + p.sta);
		System.out.println("Place name is :: " + p.pla);
	}
}
