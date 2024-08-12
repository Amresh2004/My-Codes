import java.util.Scanner;

public class Q21 
{
    String p_name;
    String p_address;
    String p_phone_no;
    static int count;

    Q21() 
    {
        p_name = "AMRESH";
        p_address = "Bijlinagar";
        p_phone_no = "8624807723";
        count++;
    }

    Q21(String p_name, String p_address, String p_phone_no) 
    {
        this.p_name = p_name;
        this.p_address = p_address;
        this.p_phone_no = p_phone_no;
        count++;
    }

    void display() 
    {
        System.out.println("Name: " + p_name);
        System.out.println("Address: " + p_address);
        System.out.println("Phone No: " + p_phone_no);
        System.out.println("The Count Of Objects is: " + count);
    }

    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        Q21 p = new Q21();
        p.display();

        System.out.print("How many people do you want: ");
        int n = sc.nextInt();
        sc.nextLine();

        Q21 p1[] = new Q21[n];

        for (int i = 0; i < n; i++) 
        {
            System.out.println("Enter Information for Person " + (i + 1) + ":");
            System.out.print("Enter Name: ");
            String p_name = sc.nextLine();
            System.out.print("Enter Address: ");
            String p_address = sc.nextLine();
            System.out.print("Enter Phone No: ");
            String p_phone_no = sc.nextLine();
            p1[i] = new Q21(p_name, p_address, p_phone_no);
            System.out.println("\nPerson Information:");
            p1[i].display();
            System.out.println();
        }
    }
}
