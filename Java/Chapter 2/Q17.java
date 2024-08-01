import java.util.Scanner;

public class Q17 {
    public static void main(String[] args) {
        int id;
        String name;
        Scanner sc=new Scanner(System.in);
        player p=new player();
        p.display();
        System.out.println("Enter Player id:- ");
        id=sc.nextInt();
        System.out.println("Eneter Name:- ");
        name=sc.next();
        player p1=new player(id ,name);
        System.out.println(p1.pid);
        System.out.println(p1.pname);
    }
}

class player
{
    int pid;
    String pname;
    player()
    {
        pid=41633;
        pname="AMRESH";
    }
    player(int id,String name)
    {
        this.pid=id;
        this.pname=name;
    }
    void display()
    {
        System.out.println("player id:- "+pid);
        System.out.println("Player name:- "+pname);
    }
}
