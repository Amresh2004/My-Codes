import java.util.Scanner;

public class Q2 {
    int rno;
    String name;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Q2 q=new Q2();
        System.out.println("Enter roll no");
        q.rno=sc.nextInt();
        System.out.println("Enter the name");
        q.name=sc.next();
    }
}
