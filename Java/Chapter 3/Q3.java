import java.util.*;

class continent
{
    String cont;
    Scanner sc=new Scanner(System.in);
    void cont_input()
    {
        System.out.println("Enter the Continent Name: ");
        cont=sc.next();
    }
}

class country extends continent
{
    String count;
    Scanner sc=new Scanner(System.in);
    void count_input()
    {
        System.out.println("Enter Country Name: ");
        count=sc.next();
    }
}

class state extends country{
    String sta;
    Scanner sc=new Scanner(System.in);
    void sta_input()
    {
        System.out.println("Enter State NAme ");
        sta=sc.next();
    }
}

class place extends state
{
    String plc;
    Scanner sc=new Scanner(System.in);
    void plc_input()
    {
        System.out.println("Enter the Place name: ");
        plc=sc.next();
    }
}

public class Q3 {
    public static void main(String[] args) {
        place p=new place();
        p.cont_input();
        p.count_input();
        p.sta_input();
        p.plc_input();
        System.out.println("Continent nAme is: "+ p.cont);
        System.out.println("Country nAme is: "+ p.count);
        System.out.println("State nAme is: "+ p.sta);
        System.out.println("Place nAme is: "+ p.plc);
    }
}
