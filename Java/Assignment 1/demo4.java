public class demo4 {
    public static void main(String[] args)
    {
    int a=35, b=25;
    System.out.println("Value of a is " +a);
    System.out.println("Value of b is " +b);
    System.out.println("Logical AND && result is " + ((a % 5 == 0) && (a % 7 == 0)));    
    System.out.println("Logical OR || result is " + ((b % 7 == 0) || (b % 3==0)));    
    System.out.println("Logical NOT ! result is " + (!(a > b)));
    }
}
