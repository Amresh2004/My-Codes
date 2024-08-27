import java.util.*;

class clg
{
    int cno;
    String cname,cadd;
}

class dept extends clg
{
    int dno;
    String dname;
    Scanner sc=new Scanner(System.in);
    void accept()
    {
        System.out.println("Enter Clg Code: ");
        super.cno=sc.nextInt();
        System.out.println("Enter Clg name: ");
        super.cname=sc.next();
        System.out.println("Enter Clg Address: ");
        super.cadd=sc.next();
        System.out.println("Enter department code: ");
        dno=sc.nextInt();
        System.out.println("Enter department name: ");
        dname=sc.next();
    }
    void display()
    {
        System.out.println("clg code is: "+ super.cno);
        System.out.println("clg name is: "+ super.cname);
        System.out.println("clg address is: "+ super.cadd);
        System.out.println("dept code is: "+ dno);
        System.out.println("dept name is: "+ dname);
    }
}

public class Q4 {
    public static void main(String[] args) {
        dept d=new dept();
        d.accept();
        d.display();
    }
}
