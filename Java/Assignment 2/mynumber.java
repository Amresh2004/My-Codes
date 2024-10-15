/*mport java.util.Scanner;

class MyNumber {
    private int n;

    // Default constructor
    MyNumber() {
        this.n = 0;
    }

    // Parameterized constructor
    MyNumber(int n) {
        this.n = n;
    }

    // Method to check if the number is positive
    public void isPositive() {
        if (n > 0) {
            System.out.println(n + " is Positive");
        }
    }

    // Method to check if the number is negative
    public void isNegative() {
        if (n < 0) {
            System.out.println(n + " is Negative");
        }
    }

    // Method to check if the number is even
    public void isEven() {
        if (n % 2 == 0) {
            System.out.println(n + " is Even");
        }
    }

    // Method to check if the number is odd
    public void isOdd() {
        if (n % 2 != 0) {
            System.out.println(n + " is Odd");
        }
    }

 public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number:");
        int x = sc.nextIn
*/
/*import java.util.*;
class mynumber
{
 private int n;
 mynumber()
 {
 n = 0;
 }
 mynumber(int n)
 {
 this.n= n;
 }
 public void ispositive(int x)
 {
 if(x>0)
 System.out.println("Positive");
 }
 public void isnegative(int x)
 {
 if(x<0)
 System.out.println("Negative");
 }
 public void iseven(int x)
 {
 if(x%2==0)
 System.out.println("Even");
 }
 public void isodd(int x)
 {
 if(x%2==1)
 System.out.println("Odd");
 }
public static void main(String args[])
 {
   Scanner sc=new Scanner(System.in);
   System.out.println("Eneter the number");
   int x=sc.nextInt();
 int n = Integer.parseInt(args[0]);
 mynumber m = new mynumber();
 m.ispositive(n);
 m.isnegative(n);
 m.iseven(n);
 m.isodd(n);
 }
*/



/*import java.util.*;
class mynumber
{
 private int n;
 mynumber()
 {
 n = 0;
 }
 mynumber(int n)
 {
 this.n= n;
 }
 public void ispositive(int n)
 {
 if(n>0)
 System.out.println("Positive");
 }
 public void isnegative(int n)
 {
 if(n<0)
 System.out.println("Negative");
 }
 public void iseven(int n)
 {
 if(n%2==0)
 System.out.println("Even");
 }
 public void isodd(int n)
 {
 if(n%2==1)
 System.out.println("Odd");
 }
public static void main(String args[])
 {
 Scanner sc=new Scanner(System.in);
 System.out.println("Enter the number: ");
 int n=sc.nextInt();
 mynumber m = new mynumber(n);
 m.ispositive(n);
 m.isnegative(n);
 m.iseven(n);
 m.isodd(n);
 }
}*/






import java.util.*;
class mynumber
{
	private int n;
	mynumber()
	{
		n = 0;
	}
	mynumber(int n)
	{
		this.n= n;
	}
	public void ispositive(int x)
	{
		if(x>0)
			System.out.println("Positive");
	}
	public void isnegative(int x)
	{
		if(x<0)
			System.out.println("Negative");
	}
	public void iseven(int x)
	{
		if(x%2==0)
			System.out.println("Even");
	}
	public void isodd(int x)
	{
		if(x%2==1)
			System.out.println("Odd");
	}
	public static void main(String args[])
	{
		int n = Integer.parseInt(args[0]);
		mynumber m = new mynumber();
		m.ispositive(n);
		m.isnegative(n);
		m.iseven(n);
		m.isodd(n);
	}
}
