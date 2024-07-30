public class Q12 {
    double l,b;
    Q12()
    {
        l=1.5;
        b=2.5;
    }
    void area()
    {
        System.out.println("Area of rectangle is:- "+(l*b));
    }
    public static void main(String[] args) {
        Q12 r=new Q12();
        r.area();
    }
}
