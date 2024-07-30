public class Q13 {
    public static void main(String[] args) {
        circle c=new circle();
        c.area();
    }
}

class circle{
    double r;
    circle()
    {
        r=1.5;
    }
    void area()
    {
        System.out.println("Area of Circle:- "+(3.14*r*r));
    }
}