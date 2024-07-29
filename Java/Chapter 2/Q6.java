import java.util.Scanner;

class addition{
    int a,b;
    Scanner sc=new Scanner(System.in);
    void accept()
    {
        System.out.println("Enter the A & b no: ");
        a=sc.nextInt();
        b=sc.nextInt();
    }
    void sum()
    {
        System.out.println("addition is "+ (a+b));
    }
}

public class Q6 {
    public static void main(String a[])
    {
        addition A=new addition();
        A.accept();
        A.sum();
    }
}
