import java.util.Scanner;

class student{
    int rno;
    String name;
    void setdata(int rno,String name)
    {
        this.rno=rno;
        this.name=name;
    }
    void putdata()
    {
       System.out.println("Roll no:- "+rno);
       System.out.println("Name is:- "+name);
    }
}
public class Q8 {
    public static void main(String a[])
    {
        int rno;
        String name;
        /*student s=new student();
          s.setdata(101,"amresh");
          s.putdata();*/

       // OR

        Scanner sc=new Scanner(System.in);
        System.out.println("enter the rno");
        rno=sc.nextInt();
        System.out.println("enter name");
        name=sc.next();
        student s1=new student();
        s1.setdata(rno,name);
        s1.putdata();
    }
}
