public class Q15 {
    public static void main(String[] args) {
        student s1=new student(41633, "AMRESH");
        s1.display();
        student s2=new student(41632, "MITESH");
        s2.display();
        student s3=new student(41635, "SHUBHAM");
        s3.display();
    }    
}

class student
{
    int rno;
    String name;
    student(int r,String s)
    {
        this.rno=r;
        this.name=s;
    }
    void display()
    {
        System.out.println("Roll No is:- "+rno);
        System.out.println("Name is:- "+name);
    }
}