import java.io.*;
import java.util.*;
class employee
{
	double salary;
	employee()
	{
		salary = 35000;
	}
	public double getsalary()
	{
		Scanner sc = new Scanner(System.in);
		double withdraw;
		System.out.println("Enter the salary which employee want to withdraw ");
		withdraw =sc.nextDouble();
		return (salary - withdraw);
	}
}
class manager extends employee 
{
	double traveling,rent;
	manager()
	{
		traveling = 2000;
		rent= 5000;
	}
	public double getsalary()
	{
		return (super.salary + traveling+rent);
	}
}
class edemo
{
	public static void main(String args[])
	{
		employee e = new employee();
		manager m = new manager();
		System.out.println("Employee salary is " + e.salary + "\nEmployee salary ifter withdraw is" +e.getsalary());
		System.out.println("Manager Salary is"+m.getsalary());
	}
}
