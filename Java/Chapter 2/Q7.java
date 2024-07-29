import java.util.Scanner;

class number{
    int y;
    void input(int x)
    {
        y=x;
    }
    void output()
    {
        System.out.println("Value of Y is: "+y);
    }
}
public class Q7 {
    public static void main(String[] args) {
        int b;
        number n=new number();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter no");
        b=sc.nextInt();
        n.input(b);
        n.output();
    }
}
