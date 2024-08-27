import java.util.*;

class A
{
    int n;
    void acceptA()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter first no: ");
        n=sc.nextInt();
    }
}

class B extends A{
    int n1;
    void acceptB()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter Second Nynber: ");
        n1=sc.nextInt();
    }
}

public class Q1 {
    public static void main(String[] args) {
        B b=new B();
        b.acceptA();
        b.acceptB();
    }
}
