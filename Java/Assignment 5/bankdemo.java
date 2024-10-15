import java.io.*;
abstract class bank
{
	public abstract void getbalance();
}
class bankA extends bank
{
	double balance = 100;
	public void getbalance()
	{
		System.out.println("Bank balance of BankA is "+balance);
	}
}
class bankB extends bank
{
	double balance = 150;
	public void getbalance()
	{
		System.out.println("Bank balance of BankB is "+balance);
	}
} 
class bankC extends bank
{
	double balance = 200;
	public void getbalance()
	{
		System.out.println("Bank balance of BankC is "+balance);
	}
} 
class bankdemo
{
	public static void main(String args[])
	{
		bankA ba = new bankA();
		bankB bb = new bankB();
		bankC bc = new bankC();
		ba.getbalance();
		bb.getbalance();
		bc.getbalance();
	}
}

