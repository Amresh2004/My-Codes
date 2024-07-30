/*public class Q11 {
    int x;
    Q11()
    {

    }
    public static void main(String[] args) {
        Q11 q=new Q11();
        System.out.println("Value of X is:- "+ q.x);
    }
}
*/
class student{
    int rno;
    String name;
    student()
    {
        rno=41633;
        name="AMRESH";
    }

}

public class Q11{
    public static void main(String a[])
    {
        student s =new student();
        System.out.println("Roll No:- "+s.rno);
        System.out.println("Name is:- "+s.name);
    }
}