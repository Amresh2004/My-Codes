import java.util.*;
class Q4 {
    public static void main(String[] args) {
        ty t=new ty();
        t.input();
        t.display();
    }
}
class ty {

    int rno;
    String name;
    void input()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter rollno");
        rno=sc.nextInt();
        System.out.println("Enter name");
        name=sc.next();
    }
    void display()
    {
        System.out.println("Enter the value of rno"+ rno);
        System.out.println("Enter name"+name);
    }
}