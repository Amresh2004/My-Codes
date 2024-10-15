import java.io.*;
import java.util.*;
class item
{

    int ino;
    String name,dname;
    float price;
    static int cnt = 0;
    item()
    {
        cnt++;
    }
    item(int ino, String name,String dname,float price)
    {
        this.ino = ino;
        this.name=name;
        this.dname = dname;
        this.price = price;
        cnt++;

    }
    void display()
    {
        System.out.println("Id is = " +this.ino + "\n Item name = " + this.name +"\n Department name= "+this.dname +"\n Price = "+this.price + "\n number of object created =" +cnt);
    }
    public static void main(String args[])
    {
        item i= new item();
        i.display();
        item i1= new item(123,"Pen","Stationary",100);
        i1.display();
    }
}