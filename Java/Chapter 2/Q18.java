public class Q18 {
    public static void main(String[] args) {
        student s=new student();
        s.display();
        student s1=new student(41633,"AMRESH");
        s1.display();
        student s2=new student(41633,"mitesh",30);
        s2.display();
    }
}

class student
{
    int id,age;
    String name;
    student()
    {

    }
    student(int id,String name)
    {
        this.id=id;
        this.name=name;
    }
    student(int id,String name,int age)
    {
        this.id=id;
        this.name=name;
        this.age=age;
    }
    void display()
    {
        System.out.println(id+name+age);
    }
}
