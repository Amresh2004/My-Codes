import java.io.*;

class vehicle
{
    void display1()
    {
        System.out.println("I'M in a Super Class Vehicle ");
    }
}

class twoWheeler extends vehicle
{
    void display2()
    {
        System.out.println("I'M in a Subclass vehicle ");
    }
}

public class Q2 {
    public static void main(String[] args) {
        twoWheeler t=new twoWheeler();
        t.display1();
        t.display2();
    }
}
