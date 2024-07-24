import java.util.Scanner;

public class Q3 {
    int eid;
    String name;
    void display()
    {
        System.out.println("Welcome");
    }
    public static void main(String a[])
    {
        Scanner sc=new Scanner(System.in);
        Q3 q=new Q3();
        System.out.println("Enter id");
        q.eid=sc.nextInt();
        System.out.println("Enter name");
        q.name=sc.next();
        q.display();
    }
}
