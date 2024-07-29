import java.util.Scanner;

class employee{
    int id;
    float Salay;
    String name;
    void setdata(int id,String name,float Salay)
    {
        this.id=id;
        this.name=name;
        this.Salay=Salay;
    }
    void putdata()
    {
        System.out.println("id="+id);
        System.out.println("name="+name);
        System.out.println("salary="+Salay);
    }
}
public class Q9 {
    public static void main(String[] args) {
        int id;
        float Salay;
        String name;
        Scanner sc=new Scanner(System.in);
        employee e=new employee();
        System.out.println("Enter id");
        id=sc.nextInt();
        System.out.println("Enter Salay");
        Salay=sc.nextFloat();
        System.out.println("Enter name");
        name=sc.next();
        e.setdata(id,name,Salay);
        e.putdata();
    }
}
