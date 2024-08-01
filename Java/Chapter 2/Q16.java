import java.util.*;
public class Q16 {
    public static void main(String[] args) {
        int id;
        String name;
        Scanner sc=new Scanner(System.in);
        department d=new department();
        System.out.println("Depaertment information of default constructore");
        System.out.println(d.did);
        System.out.println(d.dname);
        System.out.println("Enter the id:- ");
        id=sc.nextInt();
        System.out.println("Enter name:- ");
        name=sc.next();
        department d1=new department(id,name);
        System.out.println(d1.did);
        System.out.println(d1.dname);
    }
}
class department
{
    int did;
    String dname;
    department()
    {
        did=100;
        dname="Computer";
    }
    department(int id, String name)
    {
        this.did=id;
        this.dname=name;
    }
}
