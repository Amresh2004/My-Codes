import java.util.*;

class animal
{
    public void move()
    {
        System.out.println("Animal can move");
    }
}

class cat extends animal
{
    public void display()
    {
        super.move();
        System.out.println("Cat can move and walk");
    }
}


public class Q5 {
    public static void main(String[] args) {
        cat c=new cat();
        c.display();
    }    
}
