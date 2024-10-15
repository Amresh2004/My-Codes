import java.io.*;
import java.util.*;
class bank
{
	double balance;
	bank()
	{
		balance = 0;
	}
	bank(double inbalance)
	{
		balance = inbalance;
	}
	public void deposite(double amount)
	{
		balance = balance + amount;
	}
	public void withdraw(double amount)
	{
		balance = balance - amount;
	}
	public double getbalance()
	{
		return balance;
	}
	public static void main(String args[])
	{
		bank b=new bank(1000);
		b.withdraw(250);
		System.out.println("After the withdraw balance is::" +b.balance);
		b.deposite(650);
		System.out.println("After the deposite balance is::" +b.balance);
		System.out.println("After the all the transction balance is::" +b.getbalance());
	}
}

