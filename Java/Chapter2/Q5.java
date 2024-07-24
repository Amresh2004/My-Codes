import java.util.Scanner;

public class Q5 {
    public static void main(String[] args) {
        circle c=new circle();
        c.input();
        c.display();
        rectangle r= new rectangle();
        r.input();
        r.display();
    }
}
class circle{
    double r,a;
    void input()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the Radius");
        r=sc.nextDouble();
        a=3.14*r*r;
    }
    void display()
    {
        System.out.println("the area of circle is: "+ a);
    }
}
class rectangle{
    double l,b,a;
    void input()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the length of reactangle");
        l=sc.nextDouble();
        System.out.println("Enter the bredth of reactangle");
        b=sc.nextDouble();
        a=l*b;
    }
    void display()
    {
        System.out.println("the Area Of reactangle is: "+a);
    }
}