import java.util.Scanner;

public class Q20 
{
    int eid;
    String ename;
    String dname;
    double esal;
    static int count;
    Q20() 
    {
        this.eid = 41633;
        this.ename = "AMRESH";
        this.dname = "SCIENCE";
        this.esal = 4000;
        count++;
    }
    Q20(int eid, String ename, String dname, double esal) 
    {
        this.eid = eid;
        this.ename = ename;
        this.dname = dname;
        this.esal = esal;
        count++;
    }
    void display() 
    {
        System.out.println("Employee ID: " + eid);
        System.out.println("Employee Name: " + ename);
        System.out.println("Employee Department Name: " + dname);
        System.out.println("Employee Salary: " + esal);
        System.out.println("The Count Of Objects is: " + count);
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        Q20 e = new Q20();
        e.display();
        System.out.print("How many Employees do you want: ");
        int n = sc.nextInt();
        Q20[] e1 = new Q20[n];
        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter Employee Information for Employee " + (i + 1) + ":");
            System.out.print("Enter Employee ID: ");
            int eid = sc.nextInt();
            System.out.print("Enter Employee Name: ");
            String ename = sc.next();
            System.out.print("Enter Employee Department Name: ");
            String dname = sc.next();
            System.out.print("Enter Employee Salary: ");
            double esal = sc.nextDouble();
            e1[i] = new Q20(eid, ename, dname, esal);
        }
        System.out.println("\nEmployee Information:");
        for (int i = 0; i < n; i++) 
        {
            e1[i].display();
            System.out.println();
        }
    }
}
