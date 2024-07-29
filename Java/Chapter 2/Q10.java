import java.util.Scanner;

class number{
    int x;
    int square(int n)
    {
        return n*n;
    }
}
public class Q10 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int x,z;
        number n1=new number();
        System.out.println("Enter a number");
        x=sc.nextInt();
        z=n1.square(x);
        System.out.println("square of no is:- "+z);
    }
}
